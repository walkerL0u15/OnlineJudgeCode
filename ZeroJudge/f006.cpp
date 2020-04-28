#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N,a[101];
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf(" %d",&a[i]);
	sort(a,a+N);
	printf("%d %d\n",a[N-1],a[0]);
	return 0;
}
