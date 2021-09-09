#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t,N,cnt,have;
	char hope[55],chart[55][55];
	cin>>t;
	while(t--){
		cin>>N>>hope;
		have=N*(N-1)/2;
		memset(chart,0,sizeof(chart));
		cnt=0;
		for(int i=0;i<N;++i)
			if(hope[i]=='1'){
				for(int j=0;j<N;++j)
					chart[i][j]='=',chart[j][i]='=';
				++cnt;
			}
		if(cnt==N){
			cout<<"YES\n";
			for(int i=0;i<N;++i){
				for(int j=0;j<N;++j){
					if(i==j) cout<<"X";
					else cout<<"=";
				}
				cout<<"\n";
			}
			continue;
		}
		bool find;
		for(int i=0;i<N;++i){
			if(hope[i]!='1'){
				find=false;
				for(int j=0;j<N;++j){
					if(i==j) continue;
					if(chart[i][j]==0){
						chart[i][j]='+',chart[j][i]='-';
						find=true;
						break;
					}
				}
				if(!find) break;
			}
		}
		if(!find){
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				if(chart[i][j]==0)
					chart[i][j]='=',chart[j][i]='=';
		cout<<"YES\n";
		for(int i=0;i<N;++i)
			chart[i][i]='X';
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j)
				cout<<chart[i][j];
			cout<<"\n";
		}
	}
	return 0;
}
