#include<cstdio>
#include<algorithm>
using namespace std;


struct C{
	int w,s,r;
}cows[50005];
bool cmp(C a,C b){
	return a.r>b.r;
}

int main(){
	int N;
	scanf(" %d",&N);
	for(int i=0;i<N;++i){
		scanf(" %d %d",&cows[i].w,&cows[i].s);
		cows[i].r=cows[i].w+cows[i].s;
	}
	sort(cows,cows+N,cmp);
	int total=0,ans=-2*(1e9);
	for(int i=N-1;i>=0;--i){
		ans=max(ans,total-cows[i].s);
		total+=cows[i].w;
	}
	printf("%d\n",ans);
	return 0;
}
