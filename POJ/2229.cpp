#include<cstdio>
#include<algorithm>
using namespace std;

int dp[(int)1e6+5];

int main(){
    int N;
    scanf(" %d",&N);
    dp[1]=1;
    for(int i=2;i<=N;++i){
        if(i&1) dp[i]=dp[i-1]%(int)1e9;
        else dp[i]=(dp[i-1]+dp[i/2])%(int)1e9;
    }
    printf("%d\n",dp[N]);
    return 0;
}
