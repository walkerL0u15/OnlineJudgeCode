#include<stdio.h>

int main()
{
	int beetle,candy,ans=0;
	scanf(" %d %d",&candy,&beetle);
	while(candy+beetle>=13){
		if(candy>=12)
			++ans,candy-=10,--beetle;
		else
			++candy,--beetle;
	}
	printf("%d\n",ans);
	return 0;
}
