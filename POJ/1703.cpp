#include<cstdio>
const int MaxN=1e5+5;

int dep[2*MaxN],par[2*MaxN];
void init(){
    for(int i=0;i<2*MaxN;++i)
        dep[i]=0,par[i]=i;
}
int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(dep[fx]>dep[fy]) par[fy]=fx;
    else{
        par[fx]=fy;
        if(dep[fx]==dep[fy]) ++dep[fy];
    }
    return;
}
bool same(int x,int y){
    return find(x)==find(y);
}

int main(){
    int T,N,Q,a,b;
    char c;
    scanf(" %d",&T);
    while(T--){
        init();
        scanf(" %d %d",&N,&Q);
        for(int i=0;i<Q;++i){
            scanf(" %c",&c);
            if(c=='D'){
                scanf(" %d %d",&a,&b);
                unite(a,b+MaxN);
                unite(b,a+MaxN);
            }
            else{
                scanf(" %d %d",&a,&b);
                if(same(a,b))
                    puts("In the same gang.");
                else if(same(a,b+MaxN)||same(b,a+MaxN))
                    puts("In different gangs.");
                else
                    puts("Not sure yet.");
            }
        }
    }
    return 0;
}
