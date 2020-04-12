#include<iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string N;
	int total;
	while(cin>>N&&N!="0"){
		total=0;
		for(int i=0;i<N.length();++i){
			if(i%2==0)
				total+=N[i]-48;
			else
				total-=N[i]-48;
		}
		cout<<N<<(total%11==0?" is a multiple of 11.\n":" is not a multiple of 11.\n");
	}
	return 0;
}