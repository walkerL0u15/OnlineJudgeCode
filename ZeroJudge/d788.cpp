#include<cstdio>
#include<cstring>
const int MaxN=1e5;

int N;
int bit[MaxN+10]={0};

int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x){
	while(i<=N){
		bit[i]+=x;
		i+=i&-i;
	}
	return;
}

int main(){
	int M;
	while(scanf(" %d",&N)==1){
		memset(bit,0,sizeof(bit));
		for(int i=1;i<=N;++i){
			scanf(" %d",&M);
			printf("%d\n",i-sum(M));
			add(M,1);
		}
	}
	return 0;
}
