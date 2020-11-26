#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

ll num[(int)1e5+5];
ll D(int s,int e){
	int mid=(s+e)/2;
	if((e-s+1)&1)
		return num[e]-num[mid]-(num[mid-1]-num[s-1]);
	else
		return num[e]-2*num[mid]+num[s-1];
}

int main(){
	int N;
	scanf(" %d",&N);
	for(int i=1;i<=N;++i)
		scanf(" %lld",&num[i]);
	num[0]=0;
	sort(num+1,num+N+1);
	for(int i=1;i<=N;++i)
		num[i]+=num[i-1];
	ll ans=0x3f3f3f3f;
	ll total;
	for(int i=1;i<N;++i){
		total=D(1,i)+D(i+1,N);
		if(total<ans) ans=total;
	}
	printf("%lld\n",ans*2);
	return 0;
}
