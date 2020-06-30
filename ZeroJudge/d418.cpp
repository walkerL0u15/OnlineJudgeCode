#include<stdio.h>

int main(){
	int T,N,num[10];
	scanf(" %d",&T);
	while(T--){
		scanf(" %d",&N);
		if(N==1){
			puts("1");
			continue;
		}
		for(int i=0;i<10;++i)
			num[i]=0;
		for(int i=9;i>=2;--i)
			while(N%i==0)
				++num[i],N/=i;
		if(N!=1)
			puts("-1");
		else{
			for(int i=2;i<=9;++i)
				while(num[i]>0){
					printf("%d",i);
					--num[i];
				}
			printf("\n");
		}
	}
	return 0;
}
