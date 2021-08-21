#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int Mod=1e9+7;

int dp[2005][2]={0};

int main(){
    int N,a,b,k;
    bool Left;
    scanf(" %d %d %d %d",&N,&a,&b,&k);
    if(a<b) Left=true;
    else Left=false;
    for(int i=a;i<=(Left?b-1:N);++i)
        dp[i][0]=1;
    for(int t=1;t<=k;++t){
        for(int i=(Left?1:b+1);i<=(Left?b-1:N);++i){
            int l,r;
            if(Left)
                l=1,r=(i+b-1)/2;
            else
                l=(i+b)/2+1,r=N;
            dp[i][t&1]=((dp[r][(t+1)&1]-dp[l-1][(t+1)&1])%Mod-(dp[i][(t+1)&1]-dp[i-1][(t+1)&1])%Mod)%Mod;
        }
        for(int i=(Left?1:b+1);i<=(Left?b-1:N);++i)
            dp[i][t&1]=(dp[i][t&1]+dp[i-1][t&1])%Mod;
    }
    printf("%d\n",dp[(Left?b-1:N)][k&1]+(dp[(Left?b-1:N)][k&1]<0?Mod:0));
    return 0;
}
