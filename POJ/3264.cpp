#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MaxN=5e5,INF=0x3f3f3f3f;

int N,Q;
int cows[MaxN+5];
vector<int> maxC,minC;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	scanf(" %d %d",&N,&Q);
	const int B=sqrt((float)N);
	maxC.resize(B+5);minC.resize(B+5);
	fill(maxC.begin(),maxC.end(),-1);
	fill(minC.begin(),minC.end(),INF);
	for(int i=0;i<N;++i){
		scanf(" %d",&cows[i]);
		maxC[i/B]=max(maxC[i/B],cows[i]);
		minC[i/B]=min(minC[i/B],cows[i]);
	}
	int l,r,max_h,min_h;
	while(Q--){
		max_h=-1,min_h=INF;
		scanf(" %d %d",&l,&r);
		--l;
		while(l<r&&l%B!=0){
			max_h=max(max_h,cows[l]);
			min_h=min(min_h,cows[l]);
			++l;
		}
		while(l<r&&r%B!=0){
			--r;
			max_h=max(max_h,cows[r]);
			min_h=min(min_h,cows[r]);
		}
		for(;l<r;l+=B){
			max_h=max(max_h,maxC[l/B]);
			min_h=min(min_h,minC[l/B]);
		}
		printf("%d\n",max_h-min_h);
	}
}
