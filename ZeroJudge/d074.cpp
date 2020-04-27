#include<cstdio>

int main()
{
	int N,max=-1,a;
	scanf(" %d",&N);
	while(N--){
		scanf(" %d",&a);
		if(a>max)
			max=a;
	}
	printf("%d\n",max);
	return 0;
}
