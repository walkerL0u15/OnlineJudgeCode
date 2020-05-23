#include<stdio.h>

int main()
{
	int R,A;
	scanf(" %d %d",&R,&A);
	if(R==A) A-=3;
	if(A>R-A) A=R-A;
	printf("%d+%d=%d\n",A,R-A,R);
	return 0;
}
