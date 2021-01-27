#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int N,k,cl[100005];
bool C(int mi){
	ll cnt=0;
	for(int i=N-1;i>=0;--i){
		if(cl[i]<=mi) break;
		cnt+=(cl[i]-mi)/k;
		if((cl[i]-mi)%k!=0) ++cnt;
	}
	return cnt<=mi;
}

int main(){
	scanf(" %d",&N);
	for(int i=0;i<N;++i)
		scanf(" %d",&cl[i]);
	scanf(" %d",&k);
	--k;
	sort(cl,cl+N);
	if(k==0){
		printf("%d\n",cl[N-1]);
		return 0;
	}
	int ub=1e9+1000,lb=0;
	while(ub-lb>1){
		int mid=(lb+ub)/2;
		if(C(mid))
			ub=mid;
		else lb=mid;
	}
	printf("%d\n",ub);
	return 0;
}
