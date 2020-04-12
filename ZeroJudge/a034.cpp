#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans[128];
	unsigned int num,counter;
	while(cin>>num){
		counter=127;
		while(num!=1){
			ans[counter]=num%2;
			num/=2;
			--counter;
		}
		++counter;
		cout<<"1";
		for(;counter<=127;++counter)
			cout<<ans[counter];
		cout<<"\n";
	}
	return 0;
}