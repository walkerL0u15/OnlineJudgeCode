#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N;
	cin>>N;
	cin.get();
	for(int i=0;i<N;i++){
		if(cin.get()=='1'){
			if(i%2==1)
				cout<<"Aoki\n";
			else
				cout<<"Takahashi\n";
			return 0;
		}
	}
}
