#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;

int m[1005][1005]={0};//block=1,trap=2
int mi[1005][1005][3];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct L{
	int x,y,l;
}

int main(){
	int Mx,My,sx,sy,ex,ey,block,trap;
	scanf(" %d %d %d %d %d %d",&Mx,&My,&sx,&sy,&ex,&ey);
	scanf(" %d %d",&block,&trap);
	++sx,++sy,++ex,++ey;
	fill(mi,mi+1005*1005*3,INF);
	int x,y,li;
	for(int i=0;i<1005;++i){
		m[0][i]=1,m[i][0]=1;
		m[Mx+1][i]=1,m[i][My+1]=1;
	}
	for(int i=0;i<block;++i){
		scanf(" %d %d",&x,&y);
		m[x+1][y+1]=1;
	}
	for(int i=0;i<trap;++i){
		scanf(" %d %d",&x,&y);
		m[x+1][y+1]=2;
	}
	L t;
	t.x=sx,t.y=sy,t.l=2;
	mi[sx][sy][0]=0,mi[sx][sy][1]=0,mi[sx][xy][2]=0;
	queue<L> que;
	que.push(t);
	while(!que.empty()){
		x=que.front().x,y=que.front().y,li=que.front().l;
		que.pop();
		for(int i=0;i<4;++i){
			int cx=x+dx[i],cy=y+dy[i];
			if(cx==ex&&cy==ey){
				printf("%d\n",mi[x][y][li]+1);
				return 0;
			}
			if(m[cx][cy]==0&&mi[cx][cy][0]==INF){
				mi[cx][cy][0]=mi[x][y][li]+1;
				mi[cx][cy][1]=mi[x][y][li]+1;
				mi[cx][cy][2]=mi[x][y][li]+1;
				t.x=cx,t.y=ty,t.l=li;
				que.push(t);
			}
			else if(m[cx][cy]==2&&li>0&&mi[cx][cy][li]==INF){
				mi[cx][cy][li-1]=mi[x][y][li]+1;
				t.x=cx,t.y=ty,t.l=li-1;
				que.push()
			}
		}
	}
	printf("-1\n");
	return 0;
}
