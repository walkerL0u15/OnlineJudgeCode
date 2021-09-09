#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define f first 
#define s second

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,c[25],v[25];
	cin>>N;
	for(int i=0;i<N;++i)
		cin>>v[i];
	for(int i=0;i<N;++i)
		cin>>c[i];
	int sum=0;
	for(int i=0;i<N;++i)
		if(v[i]-c[i]>0)
			sum+=v[i]-c[i];
	cout<<sum<<"\n";
	return 0;
}
