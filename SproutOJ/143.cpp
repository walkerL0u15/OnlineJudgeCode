//sprout oj
#include<cstdio>
#include<cstring>

int T,N;
int arr[105],dp[105][105][2];//0 value,1 arrive cost

void dfs(int l,int r){
    if(l+1==r) return;
    if(dp[l][r][0]!=-1) return;
    int best=1e9,cut,sum;
    for(int i=l+1;i<r;++i){
        dfs(l,i);dfs(i,r);
        sum=dp[l][i][0]+dp[i][r][0]+dp[l][i][1]+dp[i][r][1];
        if(sum<best)
            best=sum,cut=i;
    }
    dp[l][r][0]=dp[l][cut][0]+dp[cut][r][0];
    dp[l][r][1]=best;
    return;
}

int main(){
    scanf(" %d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        scanf(" %d",&N);
        for(int i=0;i<N;++i)
            scanf(" %d",&arr[i]);
        for(int i=0;i<N;++i){
            dp[i][i+1][0]=arr[i];
            dp[i][i+1][1]=0;
        }
        dfs(0,N);
        printf("%d\n",dp[0][N][1]);
    }
    return 0;
}
