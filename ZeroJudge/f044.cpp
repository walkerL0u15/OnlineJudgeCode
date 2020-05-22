#include<stdio.h>

int main()
{
	int big,small;
	scanf(" %d %d",&big,&small);
	small/=big;
	++small,big=0;
	while(small!=1)
		small/=2,big++;
	printf("%d\n",big);
	return 0;
}
