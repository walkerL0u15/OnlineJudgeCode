#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,div,place,small;
	while(cin>>N>>div>>place){
		small=N%div;
		cout<<N/div<<".";
		for(int i=0;i<place;++i){
			small*=10;
			cout<<small/div;
			small%=div;
		}
		cout<<"\n";
	}
	return 0;
}