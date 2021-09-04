#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,num,max1n=-1,max2n=-1,max1p,max2p;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>num;
		if(num>max1n){
			max2n=max1n,max2p=max1p;
			max1n=num,max1p=i;
		}
		else if(num>max2n){
			max2n=num,max2p=i;
		}
	}
	cout<<max2p<<"\n";
	return 0;
}
