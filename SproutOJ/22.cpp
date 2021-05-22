//sprout 22
#include<cstdio>
#include<stack>
#include<utility>
using namespace std;
typedef pair<int,int> P;
#define f first
#define s second

int main(){
	int T,N,g;
	long long res;
	stack<P> s;
	scanf(" %d",&T);
	while(T--){
		res=0;
		scanf(" %d",&N);
		while(N--){
			scanf(" %d",&g);
			while(!s.empty()&&s.top().f<g){
				res+=s.top().s;
				s.pop();
			}
			if(s.empty())
				s.push(make_pair(g,1));
			else if(s.top().f==g){
				res+=s.top().s;
				if(s.size()>1) ++res;
				++s.top().s;
			}
			else{
				s.push(make_pair(g,1));
				++res;
			}
		}
		printf("%lld\n",res);
		s=stack<P>();
	}
	return 0;
}
