#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,num;
	bool find;
	while(cin>>N&&N!=0){
		find=false;
		while(N--){
			cin>>num;
			if(num!=0){
				cout<<num<<" ";
				find=true;
			}
		}
		if(!find) cout<<"0";
		cout<<"\n";
	}
	return 0;
}
