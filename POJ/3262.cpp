#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long

struct C{double t,d,td;};
bool cmp(C &a,C &b){
	return a.td<b.td;
}
C cows[100004];

int main()
{
	int N;
	ll ans=0,des=0;
	scanf(" %d",&N);
	for(int i=0;i<N;++i){
		scanf(" %lf %lf",&cows[i].t,&cows[i].d);
		cows[i].td=cows[i].t/cows[i].d;
		des+=cows[i].d;
	}
	sort(cows,cows+N,cmp);
	for(int i=0;i<N;++i){
		des-=cows[i].d;
		ans+=2*cows[i].t*des;
	}
	printf("%lld\n",ans);
	return 0;
}
