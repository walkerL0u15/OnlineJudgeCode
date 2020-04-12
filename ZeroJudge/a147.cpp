#include<iostream>
using namespace std;

int main()
{
	int N;
	while(cin>>N){
		if(N==0)
			return 0;
		for(int i=1;i<N;++i)
			if(i%7!=0)
				cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}