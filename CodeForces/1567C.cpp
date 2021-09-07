#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
LL dfs(int now,int num){
	if(num==0) return 1;
	LL sum=0,sum100=0;
	for(LL i=0;i<=9;++i){
		LL g=num%10,h=now%10;
		if(g-(i+h)<=9&&g-(i+h)>=0) ++sum;
		if(num/100!=0&&g+10-(i+h)<=9&&g+10-(i+h)>=0) ++sum100;
	}
	return sum*dfs(now/10,num/10)+sum100*dfs((now+100)/10,num/10);
}
 
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,num;
	cin>>T;
	while(T--){
		cin>>num;
		cout<<dfs(0,num)-2<<"\n";
	}
}
