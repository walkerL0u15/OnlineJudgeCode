#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N,num[1001];
	while(cin>>N){
		for(int i=0;i<N;++i)
			cin>>num[i];
		for(int i=1;i<N;++i)
			for(int j=i;j>0;--j)
				if(num[j]<num[j-1])
					swap(num[j],num[j-1]);
		for(int i=0;i<N;++i)
			cout<<num[i]<<" ";
		cout<<"\n";
	}
	return 0;
}