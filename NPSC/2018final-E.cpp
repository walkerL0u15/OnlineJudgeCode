#include<cstdio>

int main(){
	int T;
	int N,K;
	scanf(" %d",&T);
	while(T--){
		scanf(" %d %d",&N,&K);
		if(N%(K+1)==0)
			printf("Labrador\n");
		else
			printf("Kitty\n");
	}
	return 0;
}