#include<iostream>
using namespace std;

int N,idx=0;
string s;
int dfs(int add){
	if(s[idx]=='1')
		return add*add;
	else if(s[idx]=='0')
		return 0;
	else{
		int res=0;
		for(int i=1;i<=4;++i){
			++idx;
			res+=dfs(add/2);
		}
		return res;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>s>>N;
	cout<<dfs(N)<<"\n";
	return 0;
}
