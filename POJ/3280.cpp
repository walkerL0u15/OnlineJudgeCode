#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[2005][2005];

int main(){
	int N,L,numa,numb;
	char c,s[2005];
	map<char,int> l;
	memset(dp,0,sizeof(dp));
	scanf(" %d %d %s",&L,&N,&s[1]);
	for(int i=0;i<L;++i){
		scanf(" %c %d %d",&c,&numa,&numb);
		l[c]=min(numa,numb);
	}
	for(int i=0;i<N;++i)
		for(int j=1;j+i<=N;++j){
			if(s[j]==s[j+i])
				dp[j][j+i]=dp[j+1][j+i-1];
			else
				dp[j][j+i]=min(dp[j][j+i-1]+l[s[j+i]],dp[j+1][j+i]+l[s[j]]);
		}
	printf("%d\n",dp[1][N]);
	return 0;
}
