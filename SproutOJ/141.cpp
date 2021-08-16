//sprout oj
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[(int)1e5+10]={0},arr[(int)1e5+10]={0};

int main(){
    int T,N;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d",&N);
        for(int i=1;i<=N;++i)
            scanf(" %d",&arr[i]);
        dp[1]=arr[1],dp[2]=arr[2];
        for(int i=3;i<=N;++i)
            dp[i]=max(dp[i-2],dp[i-3])+arr[i];
        printf("%d\n",max(dp[N],dp[N-1]));
    }
    return 0;
}
