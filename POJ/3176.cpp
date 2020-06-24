#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    int p[2][355],ans=-1;
    memset(p,0,sizeof(p));
    scanf(" %d",&N);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=i;++j){
            scanf(" %d",&p[i&1][j]);
            p[i&1][j]+=max(p[!(i&1)][j],p[!(i&1)][j-1]);
        }
    for(int i=1;i<=N;++i)
        ans=max(ans,p[N&1][i]);
    printf("%d\n",ans);
    return 0;
}
