#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int S,T;
	LL ans=0;
	cin>>S>>T;
	for(int i=0;i<=S;++i)
		for(int j=0;j<=S-i;++j)
			for(int k=0;k<=S-i-j;++k){
				if(i*j*k<=T)
					ans++;
				else
					break;
			}
	cout<<ans<<"\n";
	return 0;
}
