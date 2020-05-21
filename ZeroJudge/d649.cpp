#include<stdio.h>

int main()
{
	int N,a,b;
	while(scanf(" %d",&N)==1&&N!=0){
		a=N-1;
		b=1;
		for(int b=1;b<=N;++b,--a){
			for(int i=0;i<a;++i)
				printf("_");
			for(int i=0;i<b;++i)
				printf("+");
			puts("");
		}
		puts("");
	}
	return 0;
}
