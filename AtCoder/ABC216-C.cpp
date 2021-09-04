#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

int cnt=0;
LL N;
char ans[125];

void cal(LL num){
	if(num==0) return;
	if(num&1){
		ans[cnt++]='A';
		cal(num-1);
	}
	else{
		ans[cnt++]='B';
		cal(num>>1);
	}
	return;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>N;
	cal(N);
	reverse(ans,ans+cnt);
	cout<<ans<<"\n";
	return 0;
}
