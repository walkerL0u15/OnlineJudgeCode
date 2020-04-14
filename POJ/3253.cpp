#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N,l;
	long long ans=0;
	priority_queue<int,vector<int>,greater<int> > L;
	scanf(" %d",&N);
	for(int i=0;i<N;++i){
		scanf(" %d",&l);
		L.push(l);
	}
	while(L.size()>1){
		l=L.top();
		L.pop();
		l+=L.top();
		L.pop();
		L.push(l);
		ans+=l;
	}
	printf("%lld\n",ans);
	return 0;
}
