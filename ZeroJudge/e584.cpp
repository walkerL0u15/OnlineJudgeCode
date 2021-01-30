#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int nx,ny,X,Y;
bool m[25][25]={0};
int dfs(int x,int y){
	if(!m[x][y]) return 0;
	m[x][y]=false;
	int ans=1;
	for(int i=0;i<4;++i){
		int cx=x+dx[i],cy=y+dy[i];
		if(cx<0||cx>=X) continue;
		if(cy<0)
			cy=Y-1;
		else if(cy>=Y)
			cy=0;
		ans+=dfs(cx,cy);
	}
	return ans;
}

int main(){
    while(scanf(" %d %d",&X,&Y)==2){
        memset(m,0,sizeof(m));
		char s[40];
        for(int i=0;i<X;++i){
			scanf(" %s",s);
            for(int j=0;j<Y;++j)
				if(s[j]=='l') m[i][j]=true;
        }
        scanf(" %d %d",&nx,&ny);
        if(!m[nx][ny]){
            for(int i=0;i<X;++i)
                for(int j=0;j<Y;++j)
                    m[i][j]=!m[i][j];
        }
		dfs(nx,ny);
        int res=0;
        for(int x=0;x<X;++x)
            for(int y=0;y<Y;++y)
                if(m[x][y]) res=max(res,dfs(x,y));
        printf("%d\n",res);
    }
    return 0;
}
