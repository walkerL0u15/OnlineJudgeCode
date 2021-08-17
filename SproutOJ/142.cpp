//sprout oj
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[1005]={0};

int main(){
    int T,N,K,big,ans;
    scanf(" %d",&T);
    while(T--){
        big=-1;
        scanf(" %d %d",&N,&K);
        for(int i=1;i<=N;++i)
            scanf(" %d",&dp[i]);
        for(int i=K+1;i<=N;++i){
            big=max(big,dp[i-K]);
            dp[i]+=big;
        }
        ans=-1;
        for(int i=0;i<K;++i)
            ans=max(ans,dp[N-i]);
        printf("%d\n",ans);
    }
    return 0;
}
