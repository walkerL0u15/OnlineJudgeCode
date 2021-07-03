//sprout 44
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct P{
    int x,y,step;
    P(int x_,int y_,int step_){
        x=x_,y=y_,step=step_;
    }
};
int N,cx,cy;
bool visit[105][105];
char room[105][105];
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
int bfs(){
    queue<P> que;
    que.push(P(cx,cy,0));
    while(!que.empty()){
        P qt=que.front();que.pop();
        int x=qt.x,y=qt.y,step=qt.step;
        for(int i=0;i<4;++i){
            int nx=x+mx[i],ny=y+my[i];
            if(room[nx][ny]!='#'&&!visit[nx][ny]){
                if(room[nx][ny]=='.'){
                    visit[nx][ny]=true;
                    que.push(P(nx,ny,step+1));
                }
                else
                    return step+1;
            }
        }
    }
    return -1;
}

int main(){
    while(scanf(" %d",&N)&&N!=0){
        memset(visit,false,sizeof(visit));
        for(int i=0;i<N;++i){
            scanf(" %s",room[i]);
            for(int j=0;j<strlen(room[i]);++j)
                if(room[i][j]=='K')
                    cx=i,cy=j;
        }
        visit[cx][cy]=true;
        int ans=bfs();
        if(ans==-1)
            printf("= =\"\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
