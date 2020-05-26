#include<stdio.h>
#include<string.h>

int N,ans;
bool dashl,dashr,r[12],c[12],flag;
char chess[12][12];
bool chr[12],chl[24];
void queen(int used,int han){
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
    for(int i=han;i<N;++i)
        if(!r[i])
            for(int j=0;j<N;++j)
                if((!c[j])&&(!chr[i+j])&&(!chl[i-j+11])){
                    r[i]=true,c[j]=true,chr[i+j]=true,chl[i-j+11]=true;
                    chess[i][j]='Q';
                    queen(used+1,i+1);
                    chess[i][j]='x';
                    r[i]=false,c[j]=false,chr[i+j]=false,chl[i-j+11]=false;
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
        memset(r,false,sizeof(r));
        memset(c,false,sizeof(c));
        memset(chl,false,sizeof(chl));
        memset(chr,false,sizeof(chr));
        queen(0,0);
        printf("%d\n\n",ans);
    }
}  
