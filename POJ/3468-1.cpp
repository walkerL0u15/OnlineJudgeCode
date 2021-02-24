//測資範圍都騙人的!!!!!!!!!!!!
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=(ll)1<<20;

ll A;
ll N,Q,L,R;
ll data[280000]={0},datb[280000]={0};
void add(ll a,ll b,ll x,ll k,ll l,ll r){
	if(l>=a&&r<=b)
		data[k]+=x;
	else if(b>l&&a<r){
		datb[k]+=x*(min(r,b)-max(l,a));
		add(a,b,x,k*2+1,l,(l+r)/2);
		add(a,b,x,k*2+2,(l+r)/2,r);
	}
	return;
}
ll sum(ll a,ll b,ll k,ll l,ll r){
	if(l>=a&&r<=b)
		return datb[k]+data[k]*(r-l);
	else if(a>=r||b<=l)
		return 0;
	else{
		ll res=0;
		res+=data[k]*(min(r,b)-max(l,a));
		res+=sum(a,b,k*2+1,l,(l+r)/2)+sum(a,b,k*2+2,(l+r)/2,r);
		return res;
	}
}

int main(){
	ll N,Q;
	char cm;
	scanf(" %lld %lld",&N,&Q);
	for(ll i=0;i<N;++i){
		scanf(" %lld",&A);
		add(i,i+1,A,0,0,N);
	}
	while(Q--){
		scanf(" %c",&cm);
		if(cm=='C'){
			scanf(" %lld %lld %lld",&L,&R,&A);
			add(L-1,R,A,0,0,N);
		}
		else{
			scanf(" %lld %lld",&L,&R);
			printf("%lld\n",sum(L-1,R,0,0,N));
		}
	}
	return 0;
}
