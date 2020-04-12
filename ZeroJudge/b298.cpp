#include<iostream>
#include<vector>
using namespace std;

vector<int> fac[10001];
bool bad[10001];
bool found(int test){
	if(bad[test])
		return true;
	for(int i=0;i<fac[test].size();++i)
		if(found(fac[test][i]))
			return true;
	return false;
}

int main()
{
	int n,m,l,q,a,b;
	scanf("%d%d%d%d",&n,&m,&l,&q);
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		fac[b].push_back(a);
	}
	for(int i=0;i<l;++i){
		scanf("%d",&a);
		bad[a]=true;
	}
	for(int i=0;i<q;++i){
		scanf("%d",&a);
		printf("%s\n",(found(a)?"TUIHUOOOOOO":"YA~~"));
	}
	return 0;
}