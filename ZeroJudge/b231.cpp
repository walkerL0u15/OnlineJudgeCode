#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
#define f first
#define s second

P book[1005];//f:print s:pin

bool cmp(P &a,P &b){
	return a.s>b.s;
}

int main(){
	int N;
	while(scanf(" %d",&N)==true){
		for(int i=0;i<N;++i)
			scanf(" %d %d",&book[i].f,&book[i].s);
		sort(book,book+N,cmp);
		int time=0,ans=-1;
		for(int i=0;i<N;++i){
			time+=book[i].f;
			ans=max(time+book[i].s,ans);
		}
		printf("%d\n\n",ans);
	}
	return 0;
}
