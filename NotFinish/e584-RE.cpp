#include<stdio.h>
#include<string.h>

char world[100][100],mark;
int r,c,nr,nc,now,big=0,R,C;
const int ar[]={0,0,1,-1};
const int ac[]={1,-1,0,0};
void dfs(int rd,int cd){
    for(int i=0;i<4;++i){
        R=rd+ar[i],C=cd+ac[i];
        if(C<0) C=c-1;
        else if(C>=c) C=0;
        if(R>=0&&R<r&&world[R][C]==mark){
            world[R][C]='x';
            ++now;
            dfs(R,C);
        }
    }
    return;
}

int main()
{
    while(scanf(" %d",&c)==1){
        scanf(" %d",&r);
        big=0,now=0;
        memset(world,'x',sizeof(world));
        for(int i=0;i<r;++i)
            scanf(" %s",&world[i]);
        scanf(" %d %d",&nc,&nr);
        dfs(nr,nc);
        mark=world[nr][nc];
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(world[i][j]==mark){
                    now=1;
                    world[i][j]='x';
                    dfs(i,j);
                    if(now>big) big=now;
                }
        printf("%d\n",big);
    }
    return 0;
}
