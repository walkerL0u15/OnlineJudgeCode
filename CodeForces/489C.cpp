#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define fastio ios::sync_with_stdio(false),cin.tie(0);
#define f first 
#define s second

int main(){
	fastio
	int m,s,cnt=0;
	string small,big;
	cin>>m>>s;
	if(s==0){
		cout<<(m==1?"0 0":"-1 -1")<<"\n";
		return 0;
	}
	int t;
	for(int i=0;i<m;++i){
		t=min(s,9);
		big+='0'+t;
		s-=t;
	}
	if(s>0){
		cout<<"-1 -1\n";
		return 0;
	}
	for(int i=m-1;i>=0;--i)
		small+=big[i];
	int i=0;
	while(small[i]=='0')
		++i;
	--small[i],++small[0];
	cout<<small<<" "<<big<<"\n";
	return 0;
}
