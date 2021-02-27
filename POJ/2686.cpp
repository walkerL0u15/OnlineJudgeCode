#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double INF=(double)0x3f3f3f3f;

double dp[1<<8][30];
int d[30][30],t[10];

int main(){
	int N,M,P,A,B;
	while(scanf(" %d %d %d %d %d",&N,&M,&P,&A,&B)==5&&N!=0){
		memset(d,-1,sizeof(d));
		for(int i=0;i<1<<8;++i)
			fill(dp[i],dp[i]+30,INF);
		A--,B--;
		for(int i=0;i<N;++i)
			scanf(" %d",&t[i]);
		{
			int x,y,z;
			for(int i=0;i<P;++i){
				scanf(" %d %d %d",&x,&y,&z);
				d[x-1][y-1]=z,d[y-1][x-1]=z;
			}
		}
		dp[0][A]=0;
		double res=INF;
		for(int S=0;S<(1<<8);++S)
			for(int v=0;v<M;++v)
				for(int u=0;u<M;++u)
					if(d[v][u]>=0){
						for(int i=0;i<N;++i)
							if(!(S&(1<<i))){
								dp[S|(1<<i)][u]=min(dp[S|(1<<i)][u],dp[S][v]+(double)d[v][u]/(double)t[i]);
								if(u==B) res=min(res,dp[S|(1<<i)][u]);
							}
					}
		if(res==INF)
			printf("Impossible\n");
		else
			printf("%.3lf\n",res);
	}
	return 0;
}
