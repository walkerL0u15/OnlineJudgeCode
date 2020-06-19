#include<stdio.h>
#include<set>
using namespace std;

int map[5][5],pc,pr;
int ac[]={1,-1,0,0};
int ar[]={0,0,1,-1};
set<int> ans;
void dfs(int r,int c,int cnt,int total){
    if(cnt>=6){
        ans.insert(total);
        return;
    }
    for(int i=0;i<4;++i){
        pr=r+ar[i],pc=c+ac[i];
        if(pr>=0&&pc>=0&&pr<5&&pc<5)
            dfs(pr,pc,cnt+1,total*10+map[pr][pc]);
    }
    return;
}

int main()
{
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            scanf(" %d",&map[i][j]);
    for(int i=0;i<5;++i)
        for(int j=0;j<5;++j)
            dfs(i,j,1,map[i][j]);
    printf("%d\n",ans.size());
}
