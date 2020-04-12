#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,F,A;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A>>F;
		for(int j=0;j<F;++j){
			for(int k=1;k<=A;++k){
				for(int l=1;l<=k;++l)
					cout<<k;
				cout<<"\n";
			}
			for(int k=A-1;k>=1;--k){
				for(int l=k;l>=1;--l)
					cout<<k;
				cout<<"\n";
			}
			cout<<"\n";
		}
	}
	return 0;
}