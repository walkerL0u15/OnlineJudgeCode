#include<cstdio>
typedef long long ll;

int main(){
	ll A,N;
	scanf(" %lld %lld",&N,&A);
	if(N==0){
		printf("-1\n");return 0;
	}
	else if(N>A){
		printf("0\n");return 0;
	}
	else if(N==1){
		printf("1\n");return 0;
	}
	int cnt=1;
	ll res=N;
	while(res<=A)
		res*=N,++cnt;
	printf("%d\n",cnt-1);
	return 0;
}