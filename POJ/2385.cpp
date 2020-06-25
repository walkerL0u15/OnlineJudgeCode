#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int T,W,dp[1003][32],drop[1003];
    memset(dp,0,sizeof(dp));
    scanf(" %d %d",&T,&W);
    for(int i=1;i<=T;++i){
        scanf(" %d",&drop[i]);
        drop[i]%=2;
    }
    if(drop[1]==1) dp[1][0]=1,dp[1][1]=0;
    else dp[1][0]=0,dp[1][1]=1;
    for(int i=2;i<=T;++i)
        for(int j=0;j<=i;++j){
            if(j==0)
                dp[i][j]=dp[i-1][j]+drop[i];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
                if(j%2==1&&drop[i]==0)
                    ++dp[i][j];
                else if(j%2==0&&drop[i]==1)
                    ++dp[i][j];
            }
        }
    int ans=-1;
    for(int i=0;i<=W;++i)
        ans=max(ans,dp[T][i]);
    printf("%d\n",ans);
    return 0;
}
