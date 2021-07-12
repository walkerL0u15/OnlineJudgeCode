#include<cstdio>
#include<utility>
#include<queue>
using namespace std;

struct P{
    int r,c,step;
    P(int r_,int c_,int step_){
        r=r_,c=c_,step=step_;
    }
};

int N,R,C,sr,sc,er,ec;
bool maze[105][105],find;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

int main(){
    int N;
    scanf(" %d",&N);
    while(N--){
        scanf(" %d %d %d %d %d %d",&R,&C,&sr,&sc,&er,&ec);
        for(int i=0;i<105;++i){
            maze[0][i]=true,maze[R][i]=true;
            maze[i][0]=true,maze[i][C]=true;
        }
        getchar();
        for(int i=1;i<=R;++i){
            for(int j=1;j<=C;++j)
                maze[i][j]=getchar()-'0';
            getchar();
        }
        find=false;
        queue<P> que;
        que.push(P(sr,sc,1));
        maze[sr][sc]=true;
        while(!que.empty()){
            P p=que.front();que.pop();
            int r=p.r,c=p.c,step=p.step;
            if(r==er&&c==ec){
                printf("%d\n",step);
                find=true;
                break;
            }
            for(int i=0;i<4;++i){
                int cr=r+dr[i],cc=c+dc[i];
                if(!maze[cr][cc]){
                    maze[cr][cc]=true;
                    que.push(P(cr,cc,step+1));
                }
            }
        }
        if(!find)
            printf("0\n");
    }
    return 0;
}
