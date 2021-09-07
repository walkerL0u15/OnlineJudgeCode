#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,N;
	string s;
	cin>>T;
	while(T--){
		cin>>N>>s;
		int i=0;
		while(i<N){
			if(s[i]=='U')
				cout<<"D";
			else if(s[i]=='D')
				cout<<"U";
			else{
				if(i+1<N){
					cout<<"LR";
					++i;
				}
				else
					cout<<"R";
			}
			++i;
		}
		cout<<"\n";
	}
	return 0;
}
