#include<cstdio>
#include<cstring>
#define MOD (int)1e6

int dp[2][100005];

int main(){
    int F,A,S,B,ant[1005],ans,num;
    scanf(" %d %d %d %d",&F,&A,&S,&B);
    memset(dp,0,sizeof(dp));
    memset(ant,0,sizeof(ant));
    dp[0][0]=dp[1][0]=1;
    for(int i=0;i<A;++i){
    	scanf(" %d",&num);
    	ant[num]++;
	}
    for(int i=1;i<=F;++i){
        for(int j=1;j<=B;++j){
            if(j-1>=ant[i])
                dp[i%2][j]=(dp[i%2][j-1]+dp[(i-1)%2][j]-dp[(i-1)%2][j-ant[i]-1]+MOD)%MOD;
            else
                dp[i%2][j]=(dp[i%2][j-1]+dp[(i-1)%2][j])%MOD;
        }
    }
    ans=0;
    for(int i=S;i<=B;++i)
    	ans=(ans+dp[F%2][i])%MOD;
    printf("%d\n",ans);
    return 0;
}
