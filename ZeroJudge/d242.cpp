#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int num;
	vector<int> a;
	while(cin>>num)
		a.push_back(num);
	int N=a.size();
	int dp[N+5];
	dp[0]=1;
	vector<int> best;
	best.push_back(a[0]);
	for(int i=1;i<N;++i){
		auto it=lower_bound(best.begin(),best.end(),a[i]);
		if(it==best.end()){
			best.push_back(a[i]);
			dp[i]=best.size();
		}
		else{
			*it=a[i];
			dp[i]=(int)(it-best.begin()+1);
		}
	}
	int LCS=best.size();
	vector<int> ans;
	for(int i=N-1;i>=0&&LCS>0;--i){
		if(dp[i]==LCS){
			ans.push_back(a[i]);
			LCS--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<"\n-\n";
	for(auto it=ans.begin();it!=ans.end();++it)
		cout<<*it<<"\n";
	return 0;
}
