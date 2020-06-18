#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
#define INF 2000000

int main()
{
	int T,num[11],cnt,ans,a1,a2;
	char c;
	scanf(" %d",&T);
	getchar();
	while(T--){
		ans=INF,cnt=0;
		while(true){
			num[cnt++]=getchar()-'0';
			if(getchar()=='\n') break;
		}
		if(cnt==2){
			printf("%d\n",num[1]-num[0]);
			continue;
		}
		do{
			if(num[0]==0||num[cnt/2]==0) continue;
			a1=0,a2=0;
			for(int i=0;i<cnt/2;++i)
				a1=a1*10+num[i];
			for(int i=cnt/2;i<cnt;++i)
				a2=a2*10+num[i];
			ans=min(ans,abs(a1-a2));
		}while(next_permutation(num,num+cnt));
		printf("%d\n",ans);
	}
	return 0;
}
