#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int dp[1001][1001];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	string s1,s2;
	while(cin>>s1>>s2){
		for(int i=0;i<s1.size();++i){
			if(s1[i]==s2[0]){
				for(int j=i;j<s1.size();++j)
					dp[0][j]=1;
				break;
			}
			dp[0][i]=0;
		}
		for(int i=0;i<s2.size();++i){
			if(s2[i]==s1[0]){
				for(int j=i;j<s2.size();++j)
					dp[j][0]=1;
				break;
			}
			dp[i][0]=0;
		}
		for(int i=0;i<s1.size();++i)
			for(int j=1;j<s2.size();++j){
				if(s1[i]==s2[j])
					dp[j][i]=dp[j-1][i-1]+1;
				else
					dp[j][i]=max(dp[j-1][i],dp[j][i-1]);
			}
		printf("%d\n",dp[s2.size()-1][s1.size()-1]);
	}
	return 0;
}
