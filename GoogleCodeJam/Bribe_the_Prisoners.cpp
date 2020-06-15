#include<stdio.h>
#include<algorithm>
using namespace std;
#define MaxN 105
#define INF 200000000

int main()
{
    int T,P,N,a[MaxN],dp[MaxN][MaxN];
    scanf(" %d",&T);
    for(int Case=1;Case<=T;++Case){
        scanf(" %d %d",&P,&N);
        for(int i=1;i<=N;++i)
            scanf(" %d",&a[i]);
        a[0]=0,a[N+1]=P+1;
        for(int i=0;i<=N;++i)
            dp[i][i+1]=0;
        for(int w=2;w<=N+1;++w)
            for(int i=0;i+w<=N+1;++i){
                int l=INF;
                for(int j=i+1;j<i+w;++j)
                    if(dp[i][j]+dp[j][i+w]<l)
                        l=dp[i][j]+dp[j][i+w];
                dp[i][i+w]=a[i+w]-a[i]+l-2;
            }
        printf("Case #%d: %d\n",Case,dp[0][N+1]);
    }
    return 0;
}
