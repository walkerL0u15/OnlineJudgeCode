#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;

int main(){
	int D,M;
	scanf(" %d %d",&D,&M);
	map<char,int> ate;
	ate['N']=0,ate['P']=1,ate['S']=2,ate['C']=3;
	int mood[105][4];
	char put[105][4][5];
	queue<char> que;
	{
		char s[2005];
		scanf(" %s",s);
		for(int i=0;i<strlen(s);++i)
			que.push(s[i]);
		for(int t=1;t<=M;++t){
			for(int i=0;i<4;++i)
				scanf(" %d",&mood[t][i]);
			for(int i=0;i<4;++i)
				scanf(" %s",put[t][i]);
		}
	}
	int nm=1;
	while(D--){
		char eat=que.front();que.pop();
		printf("%c",eat);
		for(int i=0;i<strlen(put[nm][ate[eat]]);++i)
			que.push(put[nm][ate[eat]][i]);
		nm=mood[nm][ate[eat]];
	}
	printf("\n");
	return 0;
}