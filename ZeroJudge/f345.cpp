#include<cstdio>

int num[(int)1e6+5];

int main(){
	int N;
	scanf(" %d",&N);
	for(int i=0;i<N;++i)
		scanf(" %d",&num[i]);
	for(int i=N-1;i>=0;--i)
		printf("%d ",num[i]);
	printf("\n");
	return 0;
}
