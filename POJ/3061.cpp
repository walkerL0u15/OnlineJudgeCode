#include<cstdio>
#include<algorithm>
using namespace std;

int num[100005];

int main(){
	int T;
	int N,S;
	scanf(" %d",&T);
	while(T--){
		scanf(" %d %d",&N,&S);
		for(int i=0;i<N;++i)
			scanf(" %d",&num[i]);
		int ans=1e8;
		int s=0,t=0,total=num[0];
		while(s<N){
			while(t<N-1&&total<S)
				total+=num[++t];
			if(total<S) break;
			ans=min(ans,t-s+1);
			total-=num[s++];
		}
		if(ans==1e8)
			printf("0\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
