#include<iostream>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;

#define INF 100000000
typedef pair<int,int> P;

int c,r,sx,sy,ex,ey;
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
bool road[102][102];
int to[102][102];
int bfs(){
	queue<P> que;
	que.push(P(sx,sy));
	for(int i=0;i<102;++i)
		for(int j=0;j<102;++j)
			to[i][j]=INF;
	to[sy][sx]=0;
	while(!que.empty()){
		P p=que.front();que.pop();
		if(p.first==ex&&p.second==ey) break;
		for(int i=0;i<4;++i){
			int x=p.first+dx[i],y=p.second+dx[i];
			if(x>=0&&y>=0&&x<=c&&y<=r&&to[y][x]==INF&&road[y][x]!=1){
				que.push(P(x,y));
				to[y][x]=to[p.second][p.first]+1;
			}
		}
	}
	return to[ey][ex];
}


int main()
{
	int T;
	scanf(" %d",&T);
	while(T--){
		scanf(" %d %d %d %d %d %d",&r,&c,&sy,&sx,&ey,&ex);
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				scanf(" %d",&road[i][j]);
		--r,--c,--sy,--sx,--ey,--ex;
		printf("%d\n",bfs());
	}
	return 0;
}
