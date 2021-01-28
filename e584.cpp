#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int nx,ny,X,Y;
bool m[25][25]={0};
int dfs(int x,int y){
    if(x==nx&&y==ny) return -1;
    if(!m[x][y]) return 0;
    m[x][y]=false;
    int ans=1;
    for(int i=0;i<4;++i){
        int cx=x+dx[i],cy=y+dy[i];
        if(cy<0||cy>=Y) continue;
        if(cx<0)
            cx=X-1;
        else if(cx>=X) cx=0;
        int cnt=dfs(cx,cy);
        if(cnt==-1) return -1;
        ans+=cnt;
    }
    return ans;
}

int main(){
    while(scanf(" %d %d",&X,&Y)==2){
        memset(m,0,sizeof(m));
        for(int i=0;i<Y;++i){
            for(int j=0;j<X;++j){
                if(getchar()=='l')
                    m[j][i]=true;
            }
            getchar();
        }
        scanf(" %d %d",&nx,&ny);
        if(!m[nx][nt]){
            for(int i=0;i<X;++X)
                for(int j=0;j<Y;++j)
                    m[i][j]=!m[i][j];
        }
        int res=-1;
        for(int y=0;y<Y;++y)
            for(int x=0;x<X;++x)
                if(m[x][y]) res=max(res,dfs(x,y));
        printf("%d\n",res);
    }
    return 0;
}
