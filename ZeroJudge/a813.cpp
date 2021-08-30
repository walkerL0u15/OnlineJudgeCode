#include<cstdio>
#include<stack>
#include<utility>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define f first
#define s second

int main(){
	int N,h;
	ll ans=0;
	stack<P> stk;
	scanf(" %d",&N);
	while(N--){
		scanf(" %d",&h);
		while(!stk.empty()&&h>stk.top().f){
			ans+=stk.top().s;
			stk.pop();
		}
		if(!stk.empty()&&h==stk.top().f){
			ans+=stk.top().s;
			++stk.top().s;
		}
		else
			stk.push(make_pair(h,1));
		if(stk.size()>1)
			ans++;
	}
	printf("%lld\n",ans*2);
	return 0;
}
