#include<cstdio>
#include<algorithm>
using namespace std;

int dp[2][235]={0};

int main(){
    int N;
    scanf(" %d",&N);
    int *crt=dp[0],*last=dp[1];
    for(int i=1;i<=N;++i) {
        for (int j = 1; j <= i; ++j) {
            scanf(" %d", &crt[j]);
            crt[j] += max(last[j], last[j - 1]);
        }
        swap(crt,last);
    }
    int res=-1;
    for(int i=1;i<=N;++i)
        res=max(res,last[i]);
    printf("%d\n",res);
}
