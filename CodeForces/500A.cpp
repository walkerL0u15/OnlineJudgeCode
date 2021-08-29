#include<cstdio>

int N,t;
int a[30010];

bool dfs(int loc){
	if(loc>=t){
		if(loc==t) return true;
		else return false;
	}
	return dfs(loc+a[loc]);
}

int main(){
	scanf(" %d %d",&N,&t);
	for(int i=1;i<=N-1;++i)
		scanf(" %d",&a[i]);
	if(dfs(1))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
