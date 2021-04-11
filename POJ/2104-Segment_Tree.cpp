#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MaxN=1e5,MaxNN=1<<17;

int N,NN=1,M,s,e,k;
int a[MaxN+5],num[MaxN+5];
vector<int> dat[MaxNN*2];
void init(int K,int l,int r){
	if(r-l==1){
		if(l<N)
			dat[K].push_back(a[l]);
	}
	else{
		init(K*2+1,l,(l+r)/2);
		init(K*2+2,(l+r)/2,r);
		dat[K].resize(r-l);  
		merge(dat[K*2+1].begin(),dat[K*2+1].end(),dat[K*2+2].begin(),dat[K*2+2].end(),dat[K].begin());
	}
	return;
}
int query(int a,int b,int K,int l,int r,int val){
	if(a>=r||b<=l)
		return 0;
	else if(a<=l&&b>=r)
		return upper_bound(dat[K].begin(),dat[K].end(),val)-dat[K].begin();
	else
		return query(a,b,K*2+1,l,(l+r)/2,val)+query(a,b,K*2+2,(l+r)/2,r,val);
}

int main(){
	scanf(" %d %d",&N,&M);
	for(int i=0;i<N;++i)
		scanf(" %d",&a[i]);
	memcpy(num,a,sizeof(a));
	sort(num,num+N);
	while(NN<N) NN<<=1;
	init(0,0,NN);
	while(M--){
		scanf(" %d %d %d",&s,&e,&k);
		--s,--e;
		int rb=N+1,lb=-1;
		while(rb-lb>1){
			int mid=(rb+lb)/2;
			if(query(s,e+1,0,0,NN,num[mid])>=k)
				rb=mid;
			else
				lb=mid;
		}
		printf("%d\n",num[rb]);
	}
	return 0;
}
