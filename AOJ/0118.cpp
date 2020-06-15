#include<stdio.h>

int H,W,ans,ch,cw;
char f[102][102];
int ah[]={1,-1,0,0};
int aw[]={0,0,1,-1};
void dfs(int h,int w,char c){
    f[h][w]='x';
    for(int i=0;i<4;++i){
        ch=h+ah[i],cw=w+aw[i];
        if(ch>=1&&cw>=1&&ch<=H&&cw<=W&&f[ch][cw]==c){
            dfs(ch,cw,c);
        }
    }
    return;
}

int main()
{
    while(scanf(" %d %d",&H,&W)==2&&H!=0){
        ans=0;
        for(int i=1;i<=H;++i)
            for(int j=1;j<=W;++j)
                scanf(" %c",&f[i][j]);
        for(int i=1;i<=H;++i)
            for(int j=1;j<=W;++j)
                if(f[i][j]!='x'){
                    dfs(i,j,f[i][j]);
                    ++ans;
                }
        printf("%d\n",ans);
    }
    return 0;
}
