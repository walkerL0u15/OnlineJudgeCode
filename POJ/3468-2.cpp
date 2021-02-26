#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int N,Q,L,R,A;
ll bitadd[200000]={0},bit[200000]={0};
void add(ll b[],int i,int v){
	while(i<=N){
		b[i]+=v;
		i+=i&-i;
	}
	return;
}
ll sum(ll b[],int i){
	ll res=0;
	while(i>0){
		res+=b[i];
		i-=i&-i;
	}
	return res;
}

int main(){
	scanf(" %d %d",&N,&Q);
	for(int i=1;i<=N;++i){
		scanf(" %d",&A);
		add(bit,i,A);
	}
	char cm;
	while(Q--){
		scanf(" %c",&cm);
		if(cm=='C'){
			scanf(" %d %d %d",&L,&R,&A);
			add(bit,R+1,A*R);
			add(bit,L,-A*(L-1));
			add(bitadd,L,A);
			add(bitadd,R+1,-A);
		}
		else{
			scanf(" %d %d",&L,&R);
			ll res=0;
			res+=sum(bit,R)+R*sum(bitadd,R);
			res-=sum(bit,L-1)+(L-1)*sum(bitadd,L-1);
			printf("%lld\n",res);
		}
	}
	return 0;
}
