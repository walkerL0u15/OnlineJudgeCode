#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 2000000

int H,W,m,sh,sw,eh,ew,ch,cw;
char b[22][22];
int ah[]={1,-1,0,0};
int aw[]={0,0,1,-1};
void dfs(const int h,const int w,const int t){
    if(t>=11) return;

    for(int i=0;i<4;++i){
        if(b[h+ah[i]][w+aw[i]]=='1') continue;
        for(int ih=h,iw=w;ih>=1&&iw>=1&&ih<=H&&iw<=W;ih+=ah[i],iw+=aw[i]){
            if(b[ih][iw]=='3'){
                if(m>t) m=t;
                return;
            }
            else if(b[ih][iw]=='1'){
                b[ih][iw]='0';
                dfs(ih-ah[i],iw-aw[i],t+1);
                b[ih][iw]='1';
                break;
            }
        }
    }
    return;
}

int main(){
    while(scanf(" %d %d",&W,&H)==2&&W!=0){
        m=INF;
        for(int i=1;i<=H;++i)
            for(int j=1;j<=W;++j){
                scanf(" %c",&b[i][j]);
                if(b[i][j]=='2') sh=i,sw=j;
                else if(b[i][j]=='3') eh=i,ew=j;
            }
        dfs(sh,sw,1);
        if(m==INF)
            puts("-1");
        else
            printf("%d\n",m);
    }
    return 0;
}
