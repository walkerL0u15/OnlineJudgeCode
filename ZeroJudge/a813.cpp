#include<iostream>
using namespace std;

int main()
{
	unsigned int N,ans=0,big=0;
	scanf("%u",&N);
	int house[N];
	for(int i=0;i<N;++i){
		scanf("%d",&house[i]);
		big=0;
		for(int j=i-1;j>=0;--j)
			if(house[j]>=big){
				big=house[j];
				++ans;
				if(big>house[i])
					break;
			}
	}
	printf("%u",ans*2);
	return 0;
}