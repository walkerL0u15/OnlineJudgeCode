#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,N,num;
	vector<int> odd;
	cin>>T;
	while(T--){
		odd.clear();
		cin>>N;
		for(int i=1;i<=N;++i){
			cin>>num;
			if(num&1) odd.push_back(i);
		}
		if(abs((int)odd.size()-(N-(int)odd.size()))>1){
			cout<<"-1\n";
			continue;
		}
		int ans_a=0,ans_b=0,odd_size=odd.size(),even_size=N-odd.size();
		for(int i=0;i<odd.size();++i){
			ans_a+=abs(odd[i]-(i*2+1));
			ans_b+=abs(odd[i]-(i+1)*2);
		}
		if(odd_size>even_size)
			cout<<ans_a<<"\n";
		else if(even_size>odd_size)
			cout<<ans_b<<"\n";
		else
			cout<<min(ans_a,ans_b)<<"\n";
	}
	return 0;
}
