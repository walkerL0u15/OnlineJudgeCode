#include<cstdio>
#include<cstring>
const int INF=0x3f3f3f3f;

struct edge{
    int u,v,c;
}p[5050];

int main(){
    int F,N,M,W;
    int u,v,c,d[505];
    int m;
    scanf(" %d",&F);
    while(F--){
        m=0;
        memset(d,INF,sizeof(d));
        scanf(" %d %d %d",&N,&M,&W);
        for(int i=0;i<M;++i){
            scanf(" %d %d %d",&u,&v,&c);
            p[m].u=u,p[m].v=v,p[m++].c=c;
            p[m].u=v,p[m].v=u,p[m++].c=c;
        }
        for(int i=0;i<W;++i){
            scanf(" %d %d %d",&u,&v,&c);
            p[m].u=u,p[m].v=v,p[m++].c=-c;
        }
        d[1]=0;
        bool ans=false,update;
        for(int i=0;i<N;++i){
            update=false;
            for(int j=0;j<m;++j){
                edge e=p[j];
                if(d[e.u]+e.c<d[e.v]){
                    update=true;
                    d[e.v]=d[e.u]+e.c;
                    if(i==N-1)
                        ans=true;
                }
            }
            if(!update) break;
        }
        if(ans)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
