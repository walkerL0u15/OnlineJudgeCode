#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t,n;
	char c;
	int sum[55];
	cin>>t;
	while(t--){
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>c;
			if(c=='a') sum[i]=sum[i-1]+1;
			else sum[i]=sum[i-1];
		}
		bool find=false;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;j+=2){
				if(sum[j]-sum[i-1]==(j-i+1)/2){
					cout<<i<<" "<<j<<"\n";
					find=true;
					break;
				}
			}
			if(find) break;
		}
		if(!find) cout<<"-1 -1\n";
	}
	return 0;
}
