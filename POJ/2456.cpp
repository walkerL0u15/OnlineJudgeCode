#include<cstdio>
#include<algorithm>
using namespace std;

int N,C,barn[100005];
bool F(int len){
	int np=0,cow=C;
	while(np<N){
		--cow;
		if(cow==0) break;
		np=lower_bound(barn+np,barn+N,barn[np]+len)-barn;
	}
	return cow==0;
}

int main(){
	scanf(" %d %d",&N,&C);
	for(int i=0;i<N;++i)
		scanf(" %d",&barn[i]);
	sort(barn,barn+N);
	int lb=0,ub=1e9+100;
	while(ub-lb>1){
		int mid=(lb+ub)/2;
		if(F(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%d\n",lb);
	return 0;
}
