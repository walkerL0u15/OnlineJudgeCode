#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,N;
	long int b,c;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a>>b>>c;
		if(a==1)
			cout<<b+c;
		else if(a==2)
			cout<<b-c;
		else if(a==3)
			cout<<b*c;
		else
			cout<<b/c;
		cout<<"\n";
	}
	return 0;
}