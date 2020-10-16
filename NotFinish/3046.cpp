#include<cstdio>
#include<cstring>
#define MOD (int)1e7

int dp[2][100005];

int main(){
    int F,A,S,B,ant[1005],ans;
    scanf(" %d %d %d %d",&F,&A,&S,&B);
    memset(dp,0,sizeof(dp));
    memset(ant,0,sizeof(ant));
    dp[0][0]=dp[1][0]=1;
    for(int i=1;i<=A;++i){
        scanf(" %d",&ant);
        for(int j=1;j<=B;++j){
            if(j-1>=ant)
                dp[i%2][j]=(dp[i%2][j-1]+dp[(i-1)%2][j]-dp[(i-1)%2][j-ant-1]+MOD)%MOD;
            else
                dp[i%2][j]=(dp[i%2][j-1]+dp[(i-1)%2][j]+MOD)%MOD;
        }
    }
    ans=0;
    for(int i=S;i<=B;++i)
    	ans+=dp[A%2][i];
    printf("%d\n",ans);
    return 0;
}
