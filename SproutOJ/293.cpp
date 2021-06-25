#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
const int MaxN=(int)1e5;

struct Node{
    int t,maxt;
    vector<int> edge;
}tree[MaxN+10];
int T,N,a,b,ans;
int dfs(int now,int f){
    int ct;
    for(int x:tree[now].edge)
        if(x!=f){
            ct=dfs(x,now);
            tree[now].t+=ct;tree[now].maxt=max(tree[now].maxt,ct);
        }
    tree[now].maxt=max(tree[now].maxt,N-1-tree[now].t);
    return tree[now].t+1;  
}

int main(){
    srand(time(NULL));
    scanf(" %d",&T);
    while(T--){
        ans=0;
        scanf(" %d",&N);
        for(int i=0;i<N;++i){
            tree[i].maxt=0,tree[i].t=0;
            tree[i].edge.clear();
        }
        for(int i=0;i<N-1;++i){
            scanf(" %d %d",&a,&b);
            tree[a].edge.push_back(b);
            tree[b].edge.push_back(a);
        }
        int gf=0;
        dfs(gf,gf);
        for(int i=0;i<N;++i)
            if(tree[ans].maxt>tree[i].maxt)
                ans=i;
        printf("%d\n",ans);
    }
    return 0;
}
