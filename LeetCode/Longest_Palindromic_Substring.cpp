class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1000][1000];
        string ans="";
        memset(dp,false,sizeof(dp));
        for(int i=0;i<s.size();++i){
            dp[i][i]=true;
            if(ans.size()==0)
                ans+=s[i];
        }
        for(int i=0;i+1<s.size();++i)
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                if(ans.size()==1)
                    ans.assign(s,i,2);
            }
        for(int i=2;i<=s.size();++i)
            for(int j=0;j+i-1<s.size();++j)
                if(s[j]==s[j+i-1]&&dp[j+1][j+i-2]){
                    dp[j][j+i-1]=true;
                    if(ans.size()<i)
                        ans.assign(s,j,i);
                }
        return ans;
    }
};
