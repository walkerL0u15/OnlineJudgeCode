#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
#define P pair<int,int>

struct S{int h,w,step;};

int main()
{
    S now,c;
    int H,W,nh,nw,ch,cw;
    char N,g='1',m[1005][1005];
    bool used[1005][1005];
    int ah[]={1,-1,0,0};
    int aw[]={0,0,-1,1};
    scanf(" %d %d %c",&H,&W,&N);
    for(int i=1;i<=H;++i){
        scanf(" %s",&m[i][1]);
        for(int j=1;j<=W;++j)
            if(m[i][j]=='S')
                c.h=i,c.w=j,c.step=0;
    }
    for(char i='1';i<=N;++i){
        memset(used,0,sizeof(used));
        queue<S> que;que.push(c);
        while(true){
            now=que.front();que.pop();
            nh=now.h,nw=now.w;
            if(m[nh][nw]==i){
                c.h=nh,c.w=nw,c.step=now.step;
                break;
            }
            for(int i=0;i<4;++i){
                ch=nh+ah[i],cw=nw+aw[i];
                if(ch>=1&&cw>=1&&ch<=H&&cw<=W&&(!used[ch][cw])&&m[ch][cw]!='X'){
                    c.h=ch,c.w=cw,c.step=now.step+1;
                    used[ch][cw]=true;
                    que.push(c);
                }
            }
        }
    }
    printf("%d\n",now.step);
    return 0;
}
