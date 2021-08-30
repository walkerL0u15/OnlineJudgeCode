#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> P;
#define f first
#define s second

struct B{
	int L,H,R;
};
B b[30005];
priority_queue<P,vector<P>,less<P> > pq;

bool cmp(B &x,B &y){
	return x.L<y.L;
}

int main(){
	int N;
	pq.push(make_pair(0,2e9));
	while(scanf(" %d",&N)&&N!=0){
		for(int i=0;i<N;++i)
			scanf(" %d %d %d",&b[i].L,&b[i].H,&b[i].R);
		sort(b,b+N,cmp);
		int cur=b[0].L;
		printf("%d",b[0].L);
		for(int i=0;i<N;++i){
			while(pq.top().s<b[i].L){
				if(pq.top().s<=cur){
					pq.pop();
					continue;
				}
				cur=pq.top().s;
				printf(" %d %d",pq.top().f,cur);
				pq.pop();
			}
			if(cur<b[i].L&&pq.top().f<b[i].H){
				cur=b[i].L;
				printf(" %d %d",pq.top().f,cur);
			}
			pq.push(make_pair(b[i].H,b[i].R));
		}
		while(pq.top().f!=0){
			if(pq.top().s>cur){
				cur=pq.top().s;
				printf(" %d %d",pq.top().f,cur);
			}
			pq.pop();
		}
		printf(" 0\n");
	}
	return 0;
}
