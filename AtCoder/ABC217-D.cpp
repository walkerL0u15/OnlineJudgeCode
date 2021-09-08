#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int L,Q,c,x;
	set<int> cut;
	cin>>L>>Q;
	cut.insert(0);cut.insert(L);
	while(Q--){
		cin>>c>>x;
		if(c==1)
			cut.insert(x);
		else{
			auto it=cut.upper_bound(x);
			cout<<*it-*(--it)<<"\n";
		}
	}	
	return 0;
}
