#include<iostream>
using namespace std;

int main()
{
	int c,num,coin[7]={1,5,10,50,100,500,1000};
	while(scanf(" %d",&num)!=EOF){
		printf("%d =",num);
		for(int i=6;i>=0;--i){
			c=0;
			while(num-coin[i]>=0){
				num-=coin[i];
				++c;
			}
			if(c!=0){
				printf(" %d*%d",coin[i],c);
				if(num!=0)
					printf(" +");
				else{
					puts("");
					break;
				}
			}
		}
	}
	return 0;
}
