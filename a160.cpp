#include<stdio.h>
#include<string.h>

int N,ans;
bool dashl,dashr,r[12],c[12],flag;
char chess[12][12];
bool ch[12][12];
void queen(int used){
    if(used>=N){
        flag=true;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j)
                printf("%c",chess[i][j]);
            puts("");
        }
        puts("");
        ++ans;
    }
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(!ch[i][j]){
                chess[i][j]='Q';
                queen(used+1);
                chess[i][j]='0';
            }
    return;
}

int main()
{
    while(scanf(" %d",&N)&&N!=0){
        ans=0;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                chess[i][j]='x';
        memset(ch,false,sizeof(ch));
        queen(0);
        printf("%d\n\n",ans);
    }
}
