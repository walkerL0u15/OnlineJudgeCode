#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N,a[102];
	scanf(" %d",&N);
	for(int i=0;i<N;++i)
		scanf(" %d",&a[i]);
	sort(a,a+N);
	for(int i=0;i<=N-1;++i)
		if(i+a[0]!=a[i]){
			printf("%d %d no\n",a[0],a[N-1]);
			return 0;
		}
	printf("%d %d yes\n",a[0],a[N-1]);
	return 0;
}
