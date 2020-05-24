#include<stdio.h>
#include<algorithm>

bool f=false;
int N,M,num[31],use[31];
void dfs(int u,int t,int i){
    if(t==M){
        f=true;
        for(int i=1;i<u;++i)
            printf("%d ",use[i]);
        puts("");
        return;
    }
    else if(t>M||i>N) return;
    use[u]=num[i];
    dfs(u+1,t+num[i],i+1);
    dfs(u,t,i+1);
    return;
}

int main()
{
    scanf(" %d %d",&N,&M);
    for(int i=1;i<=N;++i)
        scanf(" %d",&num[i]);
    std::sort(num+1,num+N+1);
    dfs(1,0,1);
    if(!f)
        puts("-1");
    return 0;
}
