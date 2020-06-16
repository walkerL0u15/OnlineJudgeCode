#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
#define MaxN 50003

struct D{int x,y,t;};
bool cmp(D &a,D &b){
    return a.t<b.t;
}

int main()
{
    int N,time=1,d=0;
    D star[50003],s;
    bool land[305][305],safe[305][305];
    int ax[]={1,-1,0,0};
    int ay[]={0,0,1,-1};
    memset(land,1,sizeof(land));
    memset(safe,1,sizeof(safe));
    scanf(" %d",&M);
    for(int i=0;i<M;++i){
        scanf(" %d %d %d",&star[i].x,&star[i].y,&star[i].t);
        ++star[i].x,++star[i].y;
        safe[star[i].x][star[i].y]=false;
        for(int j=0;j<4;++j)
            safe[star[i].x+ax[j]][star[i].y+ay[j]]=false;
    sort(star,star+M,cmp);
    queue<D> que;
    que.push({0,0,0});
    while(!que.empty()){
        s=que.front();que.pop();

        if(star[d].t==time){
            land[star[d].x][star[d].y]=false;
            for(int i=0;i<4;++i)
                land[star[d].x+ax[i]][star[d].y+ay[i]]=false;
        }

    }
    return 0;
}
