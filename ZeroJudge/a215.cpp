#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long int n,m,a;
	while(cin>>n>>m){
		a=0;
		while(m>=0){
			m-=n;
			++n;
			++a;
		}
		cout<<(a>0?a:1)<<endl;
	}
	return 0;
}