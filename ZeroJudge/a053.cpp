#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N;
	while(cin>>N){
		if(N<10)
			cout<<N*6;
		else if(N<20)
			cout<<40+2*N;
		else if(N<40)
			cout<<60+N;
		else
			cout<<100;
		cout<<"\n";
	}
	return 0;
}