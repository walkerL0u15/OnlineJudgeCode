#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

int main(){
	int T,N;
	char s[55];
	scanf(" %d",&T);
	while(T--){
		bool ans=true;
		scanf(" %d",&N);
		set<char> gift[105];
		for(int i=0;i<N;++i){
			scanf(" %s",s);
			for(int j=0;j<strlen(s);++j)
				gift[i].insert(s[j]);
		}
		for(int i=0,j=N-1;i<j;++i,--j){
			bool f=false;
			for(auto c=gift[i].begin();c!=gift[i].end();++c)	
				if(gift[j].find(*c)!=gift[j].end()){f=true;break;}
			if(!f){
				ans=false;break;
			}
		}
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}