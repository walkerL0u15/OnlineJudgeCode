#include<cstdio>
#include<algorithm>
using namespace std;

int L,N,M;
int rock[50005];
bool C(int d){
	int pre=0,now,used=0;
	for(now=1;now<N+1;++now){
		if(rock[now]-rock[pre]<d)
			++used;
		else
			pre=now;
	}
	if(rock[N+1]-rock[pre]<d) ++used;
	return used<=M;
}

int main(){
	scanf(" %d %d %d",&L,&N,&M);
	for(int i=1;i<=N;++i)
		scanf(" %d",&rock[i]);
	rock[0]=0,rock[N+1]=L;
	sort(rock+1,rock+N+1);
	if(C(L)){
		printf("%d\n",L);
		return 0;
	}
	int ll=0,ml=L;
	while(ml-ll>1){
		int mid=(ml+ll)/2;
		if(C(mid))
			ll=mid;
		else
			ml=mid;
	}
	printf("%d\n",ll);
	return 0;
}
