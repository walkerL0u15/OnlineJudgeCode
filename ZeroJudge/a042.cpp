#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	unsigned int N,ans;
	while(cin>>N){
		if(N==0){
			cout<<"1\n";
			continue;
		}
		ans=2;
		for(;N>=2;--N)
			ans+=2*N-2;
		cout<<ans<<"\n";
	}
	return 0;
}