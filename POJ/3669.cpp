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
    int N,d=0,cx,cy;
    D star[MaxN],s,ch;
    bool land[305][305],safe[305][305],used[305][305];
    int ax[]={1,-1,0,0};
    int ay[]={0,0,1,-1};
    memset(land,1,sizeof(land));
    memset(safe,1,sizeof(safe));
	memset(used,0,sizeof(used));
    scanf(" %d",&N);
    for(int i=0;i<N;++i){
        scanf(" %d %d %d",&star[i].x,&star[i].y,&star[i].t);
        ++star[i].x,++star[i].y;
        safe[star[i].x][star[i].y]=false;
        for(int j=0;j<4;++j)
            safe[star[i].x+ax[j]][star[i].y+ay[j]]=false;
	}
    sort(star,star+N,cmp);
    queue<D> que;
	ch.x=1,ch.y=1,ch.t=0;
    que.push(ch);
    while(!que.empty()){
        s=que.front();que.pop();
		used[s.x][s.y]=false;
        while(star[d].t<=s.t){
            land[star[d].x][star[d].y]=false;
            for(int i=0;i<4;++i)
                land[star[d].x+ax[i]][star[d].y+ay[i]]=false;
			++d;
        }
		if(!land[s.x][s.y])
			continue;
		for(int i=0;i<4;++i){
			cx=s.x+ax[i],cy=s.y+ay[i];
			if(cx>=1&&cy>=1&&land[cx][cy]&&(!used[cx][cy])){
				if(safe[cx][cy]){
					printf("%d\n",s.t+1);
					return 0;
				}
				ch.x=cx,ch.y=cy,ch.t=s.t+1;
				que.push(ch);
				used[cx][cy]=true;
			}
		}
    }
	puts("-1");
    return 0;
}
