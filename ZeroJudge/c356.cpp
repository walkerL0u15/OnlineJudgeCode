#include<stdio.h>

int main()
{
	int N;
	scanf(" %d",&N);
	getchar();
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j){
			if(i==j)
				putchar(getchar());
			else
				getchar();
		}
	putchar('\n');
	return 0;
}
