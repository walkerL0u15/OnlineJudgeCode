#include<cstdio>
const int MaxN=1005;

int deep[MaxN],par[MaxN];

void init(int n){
    for(int i=0;i<=n;++i)
        deep[i]=0,par[i]=i;
    return;
}
int find(int a){
    if(par[a]==a)
        return a;
    return par[a]=find(par[a]);
}
void unite(int a,int b){
    int fa=find(a),fb=find(b);
    if(fa==fb) return;
    if(deep[fa]>deep[fb])
        par[fb]=fa;
    else{
        par[fa]=fb;
        if(deep[fa]==deep[fb]) ++deep[fb];
    }
    return;
}
struct XY{
    int x,y;
}dir[MaxN];

int dis(XY a,XY b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(){
    int N,d,fix[MaxN],cnt=0,xx,yy;
    char g;
    scanf(" %d %d",&N,&d);
    init(N);
    for(int i=1;i<=N;++i)
        scanf(" %d %d",&dir[i].x,&dir[i].y);
    while(scanf(" %c",&g)==1){
        if(g=='O'){
            scanf(" %d",&xx);
            for(int i=0;i<cnt;++i)
                if(dis(dir[fix[i]],dir[xx])<=d*d)
                    unite(fix[i],xx);
            fix[cnt++]=xx;
        }
        else if(g=='S'){
            scanf(" %d %d",&xx,&yy);
            if(find(xx)==find(yy))
                puts("SUCCESS");
            else
                puts("FAIL");
        }
    }
    return 0;
}
