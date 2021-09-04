#include<iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N;
	cin>>N;
	if(N<=125)
		cout<<4;
	else if(N<=211)
		cout<<6;
	else
		cout<<8;
	cout<<"\n";
	return 0;
}
