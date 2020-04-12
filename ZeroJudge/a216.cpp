#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned long int n,g,f;
	while(cin>>n){
		f=(1+n)*n/2;
		g=0;
		for(int i=n,j=1;i>=2;--i,++j)
			g+=i*j;
		g+=n;
		cout<<f<<" "<<g<<"\n";
	}
	return 0;
}