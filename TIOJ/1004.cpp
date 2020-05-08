#include<iostream>
using namespace std;

int main()
{
	int ans=1,add=1,N;
	scanf(" %d",&N);
	while(N>1){
		add*=2;
		if(N&1){
			ans+=add;
			N=(N-1)/2;
		}
		else
			N/=2;
	}
	printf("%d\n",ans);
	return 0;
}
