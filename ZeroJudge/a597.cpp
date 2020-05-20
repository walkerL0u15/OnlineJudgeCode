#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool visit[500][500];
char fl[500][500];
int r,c,count;

void bfs(int i,int j){
	if(visit[i][j]||i>=r||i<0||j>=c||j<0) return;
	else if(fl[i][j]!='J'){
		visit[i][j]=true;
		return;
	}
	visit[i][j]=true;
	++count;
	bfs(i+1,j);
	bfs(i-1,j);
	bfs(i,j+1);
	bfs(i,j-1);
	return;
}

int main()
{
	int ans,big;
	while(scanf(" %d %d",&r,&c)==2){
		big=0;
		ans=0;
		memset(visit,false,sizeof(visit));
		for(int i=0;i<r;++i)
			scanf(" %s",fl[i]);
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				if(fl[i][j]=='J'&&(!visit[i][j])){
					++ans;
					count=0;
					bfs(i,j);
					if(count>big) big=count;
				}
		printf("%d %d\n",ans,big);
	}
}