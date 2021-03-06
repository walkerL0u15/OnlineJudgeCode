#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int land[210][210];
int sea[210][210];
int dp[1010][210];
int b[1010];

int main(){
	int N,M,R;
	while(scanf(" %d %d",&N,&M)==2&&N!=0){
		{
			memset(land,INF,sizeof(land));
			memset(sea,INF,sizeof(sea));
			memset(dp,INF,sizeof(dp));
			int x,y,t;
			char sl;
			for(int i=0;i<M;++i){
				scanf(" %d %d %d %c",&x,&y,&t,&sl);
				if(sl=='S'){
					sea[x][y]=min(sea[x][y],t);
					sea[y][x]=min(sea[y][x],t);
				}
				else{
					land[x][y]=min(land[x][y],t);
					land[y][x]=min(land[y][x],t);
				}
			}
		}
		for(int k=1;k<=N;++k)
			for(int i=1;i<=N;++i)
				for(int j=1;j<=N;++j){
					land[i][j]=min(land[i][j],land[i][k]+land[k][j]);
					sea[i][j]=min(sea[i][j],sea[i][k]+sea[k][j]);
				}
        for(int i=1;i<=N;++i)
            land[i][i]=0,sea[i][i]=0;
        scanf(" %d",&R);
        for(int i=1;i<=R;++i)
            scanf(" %d",&b[i]);
        for(int i=1;i<=N;++i)
            dp[1][i]=min(dp[1][i],sea[b[1]][i]+land[i][b[1]]);
        for(int i=1;i<=R;++i)
            for(int j=1;j<=N;++j)
                for(int k=1;k<=N;++k){
                    if(dp[i-1][k]>=INF) continue;
                    if(j==k){
                        if(land[b[i-1]][b[i]]<INF)
                           dp[i][j]=min(dp[i][j],dp[i-1][j]+land[b[i-1]][b[i]]);
                    }
                    else if(land[b[i-1]][k]<INF&&sea[k][j]<INF&&land[j][b[i]]<INF)
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+land[b[i-1]][k]+sea[k][j]+land[j][b[i]]);
                }
        int ans=INF;
        for(int i=1;i<=N;++i)
            ans=min(ans,dp[R][i]);
        printf("%d\n",ans);
	}
        return 0;
}
