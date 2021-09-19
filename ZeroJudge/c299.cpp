#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second

int main(){
	fastio
	int N,m[105],min_a=3000,max_a=-1;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>m[i];
		min_a=min(min_a,m[i]);
		max_a=max(max_a,m[i]);
	}
	cout<<min_a<<" "<<max_a<<" ";
	if(max_a-min_a+1==N)
		cout<<"yes\n";
	else
		cout<<"no\n";
	return 0;
}
