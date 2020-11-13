#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int t[1000005];
int dp[1000005];

int main(){
    int N;
    scanf(" %d",&N);
    for(int i=1;i<=N;++i)
        scanf(" %d",&t[i]);
    int from,to;
    scanf(" %d %d",&from,&to);
    fill(dp,dp+1000005,INF);
    dp[from]=0;
    int cnt=1;
    while(dp[to]==INF){
        if(t[cnt]==N){
            dp[N]=min(dp[N],dp[1]+1);
            dp[1]=min(dp[1],dp[N]+1);
        }
        else{
            int p=t[cnt];
            dp[p]=min(dp[p],dp[p+1]+1);
            dp[p+1]=min(dp[p+1],dp[p]+1);
        }
        ++cnt;
        if(cnt>N) cnt=1;
    }
    for(int i=1;i<=N;++i)
        printf("%d ",dp[i]);
    //printf("%d\n",dp[to]);
    return 0;
}
