#include<cstdio>
#include<cstring>
using namespace std;
const int MaxN=500000;

int N,K,K_num;
char name[MaxN+5][15];
int card[MaxN+5];
int F[MaxN+5]={0},bit[MaxN+5];
void add(int i,int x){
	while(i<=N){
		bit[i]+=x;
		i+=i&-i;
	}
	return;
}
int sum(int i){
	int res=0;
	while(i>0){
		res+=bit[i];
		i-=i&-i;
	}
	return res;
}
void init_F(){
	for(int i=1;i<=MaxN;++i)
		for(int j=1;i*j<=MaxN;++j)
			++F[i*j];
	return;
}
int right(int l){
	return (K_num+card[K]%l-2)%l+1;
}
int left(int l){
	return (l+K_num+card[K]%l-1)%l+1;
}
int find_K(int x){
	int l=0,r=N+1;
	while(r-l>1){
		int mid=(r+l)/2;
		if(sum(mid)>=x)
			r=mid;
		else
			l=mid;
	}
	return r;
}

int main(){
	int goal=0;
	init_F();
	while(scanf(" %d %d",&N,&K)==2){
		K_num=K;
		memset(bit,0,sizeof(bit));
		for(int i=1;i<=N;++i)
			add(i,1);
		for(int i=1;i<=N;++i)
			scanf(" %s %d",name[i],&card[i]);
		for(int i=1;i<=N;++i)
			if(F[i]>F[goal]) goal=i;
		for(int i=1;i<goal;++i){
			add(K,-1);
			if(card[K]>0)
				K_num=right(N-i);
			else
				K_num=left(N-i);
			K=find_K(K_num);
		}
		printf("%s %d\n",name[K],F[goal]);
	}
	return 0;
}
