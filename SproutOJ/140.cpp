//sprout oj
#include<cstdio>
const int Mod=1000007;
int dp[(int)1e5+10][3][3]={0};//0 red,1 green,2 blue

int main(){
    int T,N;
    scanf(" %d",&T);
    dp[1][0][0]=1,dp[1][1][1]=1,dp[1][2][2]=1;
    for(int i=2;i<=(int)1e5;++i){
        for(int j=0;j<3;++j){
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%Mod;
            dp[i][j][1]=(dp[i-1][j][1]+dp[i-1][j][0])%Mod;
            dp[i][j][2]=(dp[i-1][j][2]+dp[i-1][j][0])%Mod;
        }
    }
    int total;
    while(T--){
        total=0;
        scanf(" %d",&N);
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                total+=dp[N][i][j];
        total-=dp[N][1][2]+dp[N][2][1];
        total%=Mod;
        printf("%d\n",total);
    }
    return 0;
}
