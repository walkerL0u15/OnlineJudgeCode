#include<cstdio>
#include<algorithm>
using namespace std;

int T,l,N,num[25],now;
bool used[25];
bool cmp(int a,int b){
	return a>b;
}
bool rect(int total,int idx){
	if(now==3)
		return true;
	if(total==l){
		++now;
		if(rect(0,0))
			return true;
		--now;
	}
	for(int i=idx;i<N;++i)
		if((!used[i])&&total+num[i]<=l){
			used[i]=true;
			if(rect(total+num[i],i+1))
				return true;
			used[i]=false;
		}
	return false;
}

int main()
{
	scanf(" %d",&T);
	while(T--){
		now=0;
		fill(used,used+25,false);
		l=0;
		scanf(" %d",&N);
		for(int i=0;i<N;++i){
			scanf(" %d",&num[i]);
			l+=num[i];
		}
		sort(num,num+N,cmp);
		if(l%4!=0||num[0]>l/4){
			puts("no");
			continue;
		}
		l/=4;
		if(rect(0,0))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
