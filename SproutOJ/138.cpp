//sprout oj
#include<cstdio>
using namespace std;
const int Mod=1000007;

int dp[(int)1e5+10]={0};

int main(){
    int T,N,temp[2]={1,0};
    scanf(" %d",&T);
    dp[0]=1,dp[1]=0;
    for(int i=2;i<=(int)1e5;++i){
        dp[i]=(dp[i-2]+2*temp[i&1])%Mod;
        temp[i&1]=(temp[i&1]+dp[i])%Mod;
    }
    while(T--){
        scanf(" %d",&N);
        printf("%d\n",dp[N]);
    }
    return 0;
}
