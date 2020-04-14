#include<iostream>
using namespace std;

int main()
{
	int n;
	long long a,b,x=0,y=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf(" %lld %lld",&a,&b);
		if(a==0)
			y+=b;
		else if(a==1)
			x+=b;
		else if(a==2)
			y-=b;
		else
			x-=b;
	}
	printf("%lld %lld\n",x,y);
	return 0;
}
