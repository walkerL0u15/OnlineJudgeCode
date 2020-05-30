class Solution {
public:
    int climbStairs(int n) {
        int s[5000];
        s[2]=2,s[1]=1;
        for(int i=3;i<=n;++i)
            s[i]=s[i-1]+s[i-2];
        return s[n];
    }
};
