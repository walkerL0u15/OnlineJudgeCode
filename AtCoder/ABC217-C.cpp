#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define f first 
#define s second

P p[(int)2e5+10];
bool cmp(P &a,P &b){
	return a.s<b.s;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int N;
	cin>>N;
	for(int i=1;i<=N;++i){
		p[i].f=i;
		cin>>p[i].s;
	}
	sort(p+1,p+N+1,cmp);
	for(int i=1;i<=N;++i)
		cout<<p[i].f<<" ";
	cout<<"\n";
	return 0;
}
