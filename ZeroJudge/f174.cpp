#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second

int main(){
	#ifndef ONLINE_JUDGE

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	#endif
	fastio
	int N,K;
	int cake[(int)1e5+10]={0};
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		cin>>cake[i];
		cake[i]+=cake[i-1];
	}
	int ans=0;
	for(int i=1;i<=N;++i){
		for(int j=0;j<K&&i+j<=N;++j){
			if(cake[i+j]-cake[i-1]<0)
				break;
			else
				ans=max(ans,cake[i+j]-cake[i-1]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
