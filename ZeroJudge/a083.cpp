#include<cstdio>
#define MaxN 100000
int par[MaxN*3],dep[MaxN*3];

void init(int n){
    for(int i=0;i<n;++i){
        par[i]=i;
        dep[i]=0;
    }
    return;
}
int find(int x){
    if(par[x]==x)
        return x;
    else
        return par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;

    if(dep[x]<dep[y])
        par[x]=par[y];
    else{
        par[y]=x;
        if(dep[x]==dep[y]) dep[x]++;
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}

int main()
{
    int N,T,K,x,y,ans=0;
    scanf(" %d %d",&N,&K);
    init(N*3);
    while(K--){
        scanf(" %d %d %d",&T,&x,&y);
        --x,--y;
        if(x<0||y<0||x>=N||y>=N){
            ans++;
            continue;
        }

        if(T==1){
            if(same(x,y+N)||same(x,y+2*N))
                ans++;
            else{
                unite(x,y);
                unite(x+N,y+N);
                unite(x+2*N,y+2*N);
            }
        }
        else{
            if(same(x,y)||same(x,y+2*N))
                ans++;
            else{
                unite(x,y+N);
                unite(x+N,y+2*N);
                unite(x+2*N,y);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
