#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string secret;
	while(getline(cin,secret)){
		for(int i=0;i<secret.size();++i){
			cout<<static_cast<char>(secret[i]-7);
		}
		cout<<"\n";
	}
	return 0;
}