#include<stdio.h>

int X,Y,cx,cy,ans,gx,gy;
char room[21][21];
int ax[]={1,-1,0,0};
int ay[]={0,0,1,-1};
void dfs(int nowx,int nowy){
	++ans;
	room[nowx][nowy]='#';
	for(int i=0;i<4;++i){
		gx=nowx+ax[i],gy=nowy+ay[i];
		if(gx>=0&&gy>=0&&gx<X&&gy<Y&&room[gx][gy]=='.')
			dfs(gx,gy);
	}
	return;
}

int main()
{
	while(scanf(" %d %d",&X,&Y)==2&&X!=0){
		ans=0;
		for(int i=0;i<Y;++i)
			for(int j=0;j<X;++j){
				scanf(" %c",&room[j][i]);
				if(room[j][i]=='@')
					cx=j,cy=i;
			}
		dfs(cx,cy);
		printf("%d\n",ans);
	}
	return 0;
}
