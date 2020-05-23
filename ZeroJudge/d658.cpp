#include<stdio.h>

int main()
{
	int a[20],N,cnt=1;
	a[0]=1;
	for(int i=1;a[i-1]<=10000;++i)
		a[i]=a[i-1]*2;
	while(scanf(" %d",&N)&&N>=0){
		for(int i=0;i<20;++i)
			if(a[i]>=N){
				printf("Case %d: %d\n",cnt,i);
				break;
			}
		++cnt;
	}
	return 0;
}
