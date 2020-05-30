#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int N,num[2],input=1;
	bool jolly[3001],flag;
	while(scanf(" %d",&N)==1){
		num[0]=0,num[1]=0;
		memset(jolly,0,sizeof(jolly));
		scanf(" %d",&num[input]);
		for(int i=1;i<N;++i){
			input=!input;
			scanf(" %d",&num[input]);
			jolly[(int)abs(num[input]-num[!input])]=true;
		}
		flag=true;
		for(int i=1;i<N;++i)
			if(!jolly[i]){
				flag=false;
				break;
			}
		if(flag)
			puts("Jolly");
		else
			puts("Not jolly");
	}
	return 0;
}
