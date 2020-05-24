#include<stdio.h>

int N,bug[101];
void p(){
	for(int j=0;j<N;++j)
			scanf(" %d",&bug[j]);
	for(int j=0,k=N-1;j<=k;){
		for(int l=j;l<=k;++l)
			printf("%d ",bug[l]);
		puts("");
		++j;
		for(int l=k;l>=j;--l)
			printf("%d ",bug[l]);
		--k;
		puts("");
	}
	puts("");
}

int main()
{
	while(scanf(" %d",&N)==1){
		p();
		scanf(" %d",&N);
		p();
	}
	return 0;
}
