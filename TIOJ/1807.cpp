#include<cstdio>
#include<map>
#include<set>
using namespace std;

map<int,set<int>> g;

int main(){
	int N,M;
	scanf(" %d %d",&M,&N);
	if(N>M*(M-1)/2){
		printf("Yes\n");
		return 0;
	}
	int a,b;
	for(int i=0;i<N;++i){
		scanf(" %d %d",&a,&b);
		if(a==b||(g.find(a)!=g.end()&&g[a].find(b)!=g[a].end())){
			printf("Yes\n");
			return 0;
		}
		g[a].insert(b);
		g[b].insert(a);
	}
	printf("yes\n");
	return 0;
}
