#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int d[305][305];

int main(){
    int N,M,n;
    int in[305];
    scanf(" %d %d",&N,&M);
    memset(d,INF,sizeof(d));
    for(int i=0;i<M;++i){
        scanf(" %d",&n);
        for(int j=0;j<n;++j)
            scanf(" %d",&in[j]);
        for(int j=0;j<n;++j)
            for(int k=j+1;k<n;++k)
                d[in[j]][in[k]]=1,d[in[k]][in[j]]=1;
    }
    for(int i=0;i<=N;++i)
        d[i][i]=0;
    for(int k=1;k<=N;++k)
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int total,ans=INF;
    for(int i=1;i<=N;++i){
        total=0;
        for(int j=1;j<=N;++j)
            total+=d[i][j];
        ans=min(ans,total);
    }
    printf("%d\n",ans*100/(N-1));
    return 0;
}
