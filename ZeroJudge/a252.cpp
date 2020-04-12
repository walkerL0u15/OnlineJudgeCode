#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s,t,u;
    cin>>s>>t>>u;
    int sl=s.size(),tl=t.size(),ul=u.size();
    int dp[sl+1][tl+1][ul+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<sl;++i)
        for(int j=0;j<tl;++j)
            for(int k=0;k<ul;++k){
                if(s[i]==t[j]&&s[i]==u[k])
                    dp[i+1][j+1][k+1]=dp[i][j][k]+1;
                else{
                    dp[i+1][j+1][k+1]=dp[i][j][k];
                    for(int x=0;x<=1;++x)
                        for(int y=0;y<=1;++y)
                            for(int z=0;z<=1;++z)
                                if(dp[i+x][j+y][k+z]==dp[i][j][k]+1){
                                    dp[i+1][j+1][k+1]=dp[i][j][k]+1;
                                    break;
                                }
                }
                
            }
    printf("%d\n",dp[sl][tl][ul]);
    return 0;
}