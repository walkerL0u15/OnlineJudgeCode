#include<cstdio>
#include<cstring>

int dp[100005][2];

int main(){
    int F,A,S,B,ant;
    scanf(" %d %d %d %d",&F,&A,&S,&B);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<F;++i){
        scanf(" %d",&ant);
        for(int j=1;j<=B;++j){
            if(j-1>=ant)
                dp[i&1][j]=dp[!(i&1)][j]+(dp[i&1][j-1]-dp[i&1][j-1-ant])-(dp[!(i&1)][j-1]-dp[!(i&1)][j-1-ant]);
            else
                dp[i&1][j]=dp[!(i&1)][j]+dp[i&1][j-1]-dp[!(i&1)][j-1];
        }
    }
    printf("%d\n",dp[!(F&1)][B]-dp[!(F&1)][S-1]);
    return 0;
}
