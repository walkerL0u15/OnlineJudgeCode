#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second
const int INF=1e9+10;

vector<int> p[4];
int low(int a,int b,int i){
	auto ap=lower_bound(p[a].begin(),p[a].end(),i);
	auto bp=lower_bound(p[b].begin(),p[b].end(),i);
	if(ap==p[a].end()||bp==p[b].end()) return -1;
	return max(*ap,*bp);
}

int main(){
	fastio
	int t;
	string s;
	cin>>t;
	while(t--){
		for(int i=1;i<=3;++i)
			p[i].clear();
		cin>>s;
		for(int i=0;i<s.size();++i)
			p[s[i]-'0'].push_back(i);
		int ans=INF,len;
		for(int i=0;i<s.size();++i){
			if(s[i]=='1')
				len=low(2,3,i);
			else if(s[i]=='2')
				len=low(1,3,i);
			else
				len=low(1,2,i);
			if(len==-1) continue;
			ans=min(ans,len-i+1);
		}
		if(ans==INF) cout<<"0\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
