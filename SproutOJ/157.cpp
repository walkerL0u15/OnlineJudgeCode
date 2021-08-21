#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int dp[10005];
int A[105],B[105];

int main(){
    int T,N,M;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d",&N,&M);
        for(int i=1;i<=N;++i)
            scanf(" %d %d",&A[i],&B[i]);
        memset(dp,INF,sizeof(dp));
        dp[0]=0,dp[B[1]]=A[1];
        for(int i=2;i<=N;++i)
            for(int j=10000;j>=0;--j){
                if(j-B[i]>=0)
                    dp[j]=min(dp[j],dp[j-B[i]]+A[i]);
            }
        for(int i=10000;i>=0;--i)
            if(dp[i]<=M){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
