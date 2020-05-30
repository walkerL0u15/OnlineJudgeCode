#include<stdio.h>

int main()
{
	int N,m,ans=0;
	scanf(" %d",&N);
	for(int i=1;i<=N;++i){
		scanf(" %d",&m);
		ans+=i*m;
	}
	printf("%d\n",ans);
	return 0;
}
