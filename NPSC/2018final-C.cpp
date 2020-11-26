#include<cstdio>
typedef long long ll;

ll num[100005];

int main(){
	int N;
	num[0]=0;
	scanf(" %d",&N);
	for(int i=1;i<=N;++i){
		scanf(" %lld",&num[i]);
		num[i]+=num[i-1];
	}
	ll ans=num[1];
	for(int i=1;i<=N;++i)
		for(int j=i;j<=N;++j)
			if(num[j]-num[i-1]>ans) ans=num[j]-num[i-1];
	printf("%lld\n",ans);
	return 0;
}
