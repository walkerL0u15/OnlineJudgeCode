#include<cstdio>

int dp[1005][(int)1e5+10]={0};

int main(){
    int T,A,S,B;
    scanf(" %d %d %d %d",&T,&A,&S,&B);
    int ant[1005]={0},a;
    for(int i=0;i<A;++i) {
        scanf(" %d", &a);
        ++ant[a];
    }
    dp[0][0]=1;
    for(int i=1;i<=T;++i)
        for(int j=0;j<=A;++j){
            if(j>=ant[i])
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1-ant[i]]+(int)1e6;//因可能<0
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=(int)1e6;
        }
    int res=0;
    for(int i=S;i<=B;++i)
        res=(res+dp[T][i])%(int)1e6;
    printf("%d\n",res);
    return 0;
}
