class Solution {
public:
    int numTrees(int n) {
        int method[1000];
        memset(method,0,sizeof(method));
        method[0]=1,method[1]=1;
        for(int i=2;i<=n;++i)
            for(int j=0;j<=i-1;++j)
                method[i]+=(method[j]*method[i-j-1]);
        return method[n];
    }
};
