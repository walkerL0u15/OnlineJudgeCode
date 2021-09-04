#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int S[200005],T[200005];
LL ans[200005];

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,big;
	cin>>N;
	for(int i=0;i<N;++i)
		cin>>S[i];
	for(int i=0;i<N;++i){
		cin>>T[i];
		ans[i]=T[i];
		big=max(big,T[i]);
	}
	for(int i=0;i<N;++i){
		LL t=T[i]+S[i];
		for(int j=1;j<N;++j){
			ans[(i+j)%N]=min(ans[(i+j)%N],t);
			t+=S[(i+j)%N];
			if(t>=big) break;
		}	
	}
	for(int i=0;i<N;++i)
		cout<<ans[i]<<"\n";
	return 0;
}
