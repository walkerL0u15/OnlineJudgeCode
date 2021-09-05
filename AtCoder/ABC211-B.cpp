#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define f first 
#define s second

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	set<string> st;
	string s;
	for(int i=0;i<4;++i){
		cin>>s;
		st.insert(s);
	}
	if(st.find("H")!=st.end()&&st.find("2B")!=st.end()&&st.find("3B")!=st.end()&&st.find("HR")!=st.end())
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}
