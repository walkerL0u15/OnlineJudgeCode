#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a,b,c,dir;
	cin>>a>>b>>c;
	dir=b*b-4*a*c;
	if(dir<0)
		cout<<"No real root\n";
	else if(dir==0)
		cout<<"Two same roots x="<<-b/2/a<<"\n";
	else
		cout<<"Two different roots x1="<<(-b+sqrt(dir))/2/a<<" , x2="<<(-b-sqrt(dir))/2/a<<"\n";
	return 0;
}