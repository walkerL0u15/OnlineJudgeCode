#include<cstdio>

int N,M;
int m[100005];
bool C(int mon){
	int total=0,group=0;
	for(int i=0;i<N;++i){
		total+=m[i];
		if(m[i]>mon) return false;
		if(total>mon){
			total=m[i];
			++group;
		}
	}
	if(total>0) ++group;
	return group<=M;
}

int main(){
	scanf(" %d %d",&N,&M);
	for(int i=0;i<N;++i)
		scanf(" %d",&m[i]);
	int lb=0,ub=1e9+1000;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(C(mid))
			ub=mid;
		else lb=mid;
	}
	printf("%d\n",ub);
	return 0;
}
