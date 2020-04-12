#include<iostream>
#include<algorithm>
using namespace std;

#define MaxN 100
#define MaxW 10000000
#define INF 1500000000
#define MaxV 100
int dp[MaxN+2][MaxN*MaxV+2];

int main()
{
    int n,W;
    fill(dp[0],dp[0]+MaxN*MaxV+2,INF);
    scanf(" %d %d",&n,&W);
    int v[n],w[n];
    for(int i=0;i<n;++i)
        scanf(" %d %d",&w[i],&v[i]);
    dp[0][0]=0,dp[0][v[0]]=w[0];
    for(int i=1;i<n;++i)
        for(int j=0;j<=MaxN*MaxV;++j){
            if(j<v[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);               
        }
    for(int i=MaxN*MaxV;i>=0;--i)
        if(dp[n-1][i]<=W){
            printf("%d\n",i);
            break;
        }
    return 0;
}