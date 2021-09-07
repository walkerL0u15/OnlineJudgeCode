#include<bits/stdc++.h>
using namespace std;

int candle[(int)3e5+10];
map<int,int> type;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,K;
	int ans,cnt=0;
	cin>>N>>K;
	for(int i=0;i<N;++i)
		cin>>candle[i];
	for(int i=0;i<K;++i){
		type[candle[i]]++;
		if(type[candle[i]]==1)
			++cnt;
	}
	ans=cnt;
	for(int i=1;i+K-1<N;++i){
		type[candle[i-1]]--;
		if(type[candle[i-1]]==0)
			--cnt;
		type[candle[i+K-1]]++;
		if(type[candle[i+K-1]]==1)
			++cnt;
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
