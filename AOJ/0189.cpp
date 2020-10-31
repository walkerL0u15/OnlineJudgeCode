#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int main(){
    int N,V,a,b,r,anst,ansc,total;
    int d[15][15];
    while(scanf(" %d",&N)&&N!=0){
        V=-1;
        memset(d,INF,sizeof(d));
        for(int i=0;i<=9;++i)
            d[i][i]=0;
        for(int i=0;i<N;++i){
            scanf(" %d %d %d",&a,&b,&r);
            d[a][b]=r,d[b][a]=r;
            V=max(V,max(a,b));
        }
        for(int k=0;k<=V;++k)
            for(int i=0;i<=V;++i)
                for(int j=0;j<=V;++j)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        anst=INF;
        for(int i=0;i<=V;++i){
            total=0;
            for(int j=0;j<=V;++j)
                total+=d[i][j];
            if(total<anst)
                anst=total,ansc=i;
        }
        printf("%d %d\n",ansc,anst);
    }
    return 0;
}
