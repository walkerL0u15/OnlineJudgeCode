#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int A[(int)2e5+10],B[(int)2e5+10];

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;++i)
		cin>>A[i];
	for(int i=0;i<M;++i)
		cin>>B[i];
	sort(A,A+N);
	sort(B,B+M);
	int a=0,b=0,ans=2e9;
	while(a<N&&b<M){
		ans=min(ans,abs(A[a]-B[b]));
		if(B[b]>A[a]) ++a;
		else ++b;
	}
	cout<<ans<<"\n";
	return 0;
}
