#include<bits/stdc++.h>
using namespace std;

int A[(int)2e5+10],B[(int)2e5+10];

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;++i)
		cin>>A[i];
	for(int i=1;i<=M;++i)
		cin>>B[i];
	B[0]=-2e9,B[M+1]=2e9;
	sort(B+1,B+M+1);
	int ans=2e9;
	for(int i=1;i<=N;++i){
		int *p=lower_bound(B+1,B+M+1,A[i]);
		ans=min(ans,min(abs(A[i]-*p),abs(A[i]-*(p-1))));
	}
	cout<<ans<<"\n";
	return 0;
}
