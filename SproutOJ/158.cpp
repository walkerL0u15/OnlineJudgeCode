#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[10005][105];
int A[105],B[105];

int main(){
    int T,N,M,K;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d %d",&N,&M,&K);
        for(int i=1;i<=N;++i)
            scanf(" %d %d",&A[i],&B[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=N;++i)
            for(int j=M;j-A[i]>=0;--j)
                for(int k=1;k<=K;++k)
                    if(dp[j-A[i]][k-1]!=-1)
                        dp[j][k]=max(dp[j-A[i]][k-1]+B[i],dp[j][k]);
        int ans=-1;
        for(int i=0;i<=M;++i)
            for(int j=1;j<=K;++j)
                ans=max(ans,dp[i][j]);
        printf("%d\n",ans);
    }
}
