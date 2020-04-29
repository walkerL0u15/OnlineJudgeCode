#include<iostream>
#include<vector>
using namespace std;

int E,S,a,b;
vector<int> s[105];
int path(int re){
	int total=0;
	if(re==S-1)
		return 1;
	for(int i=0;i<s[re].size();++i)
		total+=path(s[re][i]);
	return total;
}

int main()
{
	scanf(" %d %d",&S,&E);
	for(int i=0;i<E;++i){
		scanf(" %d %d",&a,&b);
		s[a].push_back(b);
	}
	printf("%d\n",path(0));
}
