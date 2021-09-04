#include<iostream>
#include<algorithm>
using namespace std;

int num[(int)1e6+10];

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;++i)
		cin>>num[i];
	sort(num,num+N);
	for(int i=0;i<N;++i)
		cout<<num[i]<<" ";
	cout<<"\n";
	return 0;
}
