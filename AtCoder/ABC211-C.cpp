#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int dp[11]={0};
	string s,want=" chokudai";
	dp[0]=1;
	cin>>s;
	for(int i=0;i<s.size();++i){
		for(int j=1;j<=8;++j){
			if(s[i]==want[j]){
				dp[j]+=dp[j-1];
				dp[j]%=Mod;
			}
		}
	}
	cout<<dp[8]<<"\n";
	return 0;
}
