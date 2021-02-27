#include<cstdio>
#include<algorithm>
using namespace std;

int dp[2][35]={0},drop;

int main(){
    int T,W;
    int *now=dp[0],*last=dp[1];
    scanf(" %d %d",&T,&W);
    for(int i=1;i<=T;++i){
        scanf(" %d",&drop);
        drop=drop-1;
        now[0]=last[0]+(!drop);
        for(int j=1;j<=W;++j)
            now[j]=max(last[j],last[j-1])+(((j+1)&1)^drop);
        swap(now,last);
    }
    int res=-1;
    for(int i=0;i<=W;++i)
        res=max(res,last[i]);
    printf("%d\n",res);
    return 0;
}
