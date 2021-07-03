//sprout 42
#include<cstdio>
#include<cstring>
using namespace std;

int T,H,W;
bool visit[1005][1005],water[1005][1005];
int mh[]={1,-1,0,0};
int mw[]={0,0,1,-1};
void dfs(int h,int w){
    for(int i=0;i<4;++i){
        int nh=h+mh[i],nw=w+mw[i]; 
        if(water[nh][nw]&&!visit[nh][nw]){
            visit[nh][nw]=true;
            dfs(nh,nw);
        }
    }
    return;
}

int main(){
    scanf(" %d",&T);
    while(T--){
        memset(visit,false,sizeof(visit));
        memset(water,false,sizeof(water));
        scanf(" %d %d",&H,&W);
        getchar();
        for(int i=1;i<=H;++i){
            for(int j=1;j<=W;++j){
                if(getchar()=='.')
                    water[i][j]=true;
                else
                    water[i][j]=false;
            }
            getchar();
        }
        int cnt=0;
        for(int i=1;i<=H;++i)
            for(int j=1;j<=W;++j)
                if(water[i][j]&&!visit[i][j]){
                    visit[i][j]=true;
                    dfs(i,j);
                    ++cnt;
                }
        printf("%d\n",cnt);
    }
    return 0;
}
