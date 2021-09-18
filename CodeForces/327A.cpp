#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second

int main(){
	int n,one[105]={0};
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>one[i];
		one[i]+=one[i-1];
	}
	int ans=-1;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
			ans=max(ans,j-i+1-2*(one[j]-one[i-1]));
		}
	cout<<one[n]+ans<<"\n";
	return 0;
}
