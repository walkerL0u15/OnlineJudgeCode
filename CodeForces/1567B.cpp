#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
LL num[(int)3e5+10];
 
int main(){
	LL T,a,b;
	LL x;
	scanf(" %lld",&T);
	num[0]=0;
	for(int i=1;i<=(int)3e5;++i)
		num[i]=(LL)(num[i-1]^i);
	while(T--){
		scanf(" %lld %lld",&a,&b);
		x=num[a-1];
		if(x==b)
			printf("%lld\n",a);
		else if((int)(x^b)==a)
			printf("%lld\n",a+2);
		else
			printf("%lld\n",a+1);
	}
	return 0;
}
