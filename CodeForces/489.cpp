#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int n,m;
int boy[105],girl[105];

int main(){
	scanf(" %d",&n);
	for(int i=0;i<n;++i)
		scanf(" %d",&boy[i]);
	scanf(" %d",&m);
	for(int i=0;i<m;++i)
		scanf(" %d",&girl[i]);
	sort(boy,boy+n);
	sort(girl,girl+m);
	int g=0,ans=0;
	for(int b=0;b<n;++b){
		while(boy[b]-1>girl[g]&&g<m)
			++g;
		if(abs(boy[b]-girl[g])<=1)
			++ans,++g;
	}
	printf("%d\n",ans);
}
