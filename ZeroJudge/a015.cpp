#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int row,column;
	int space[101][101];
	
	while(cin>>row>>column){
		for(int i=0;i<row;++i)
			for(int j=0;j<column;++j)
				cin>>space[i][j];
		for(int i=0;i<column;++i){
			for(int j=0;j<row;++j)
				cout<<space[j][i]<< " ";
			cout<<"\n";
		}
	}
	return 0;
}