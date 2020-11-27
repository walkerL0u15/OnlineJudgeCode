#include<cstdio>
#include<algorithm>
using namespace std;

int gr[30][30][360]={0};
int num[360],sc[30][30];

int main(){
	int R,C;
	int a=1;
	bool f;
	num[0]=20;
	scanf(" %d %d",&R,&C);
	for(int i=1;i<=R;++i)
		for(int j=1;j<=C;++j){
			scanf(" %d",&sc[i][j]);
			f=false;
			for(int k=a-1;k>=0;--k)
				if(num[k]==sc[i][j]){
					f=true;
					gr[i][j][k]=1;
					break;
				}
			if(!f){
				num[a++]=sc[i][j];
				gr[i][j][a]=1;
			}
			for(int k=0;k<=a;++k)
				gr[i][j][k]+=gr[i-1][j][k]+gr[i][j-1][k]-gr[i-1][j-1][k];
		}
	int big,ans=-1;
	for(int rs=1;rs<=R;++rs)
		for(int re=rs;re<=R;++re)
			for(int cs=1;cs<=C;++cs)
				for(int ce=cs;ce<=C;++ce){
					big=-1;
					for(int i=0;i<=a;++i)
						big=max(big,gr[re][ce][i]-gr[rs-1][ce][i]-gr[re][cs-1][i]+gr[rs-1][cs-1][i]);
					ans=max(ans,big-(gr[re][ce][0]-gr[rs-1][ce][0]-gr[re][cs-1][0]+gr[rs-1][cs-1][0]));
				}
	printf("%d\n",gr[R][C][0]+ans);
	return 0;
}
