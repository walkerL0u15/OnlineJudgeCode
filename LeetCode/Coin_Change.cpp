class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        const int am=amount,INF=50000000;
        int dp[am+1];
        sort(coins.begin(),coins.end());
        fill(dp,dp+am+1,INF);
        dp[0]=0;
        for(int i=0;i<coins.size();++i){
            if(coins[i]>amount)
                break;
            dp[coins[i]]=1;
        }
        for(int i=1;i<=amount;++i)
            for(int j=0;j<coins.size();++j){
                if(i-coins[j]<0)
                    break;
                if(dp[i-coins[j]]!=INF)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        return (dp[amount]==INF?-1:dp[amount]);
    }
};
