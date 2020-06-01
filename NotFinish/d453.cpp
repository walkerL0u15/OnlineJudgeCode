#include<stdio.h>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;

#define P pair<int,int>

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int N,lia,han,slia,shan,elia,ehan;
	int w[100][100];
	bool puzzle[101][101],f;
	int addhan[4]={1,0,-1,0};
	int addlia[4]={0,-1,0,1};
	string t;
	queue<P> p;
	P test;
	scanf(" %d",&N);
	while(N--){
		f=false;
		memset(w,0,sizeof(w));
		scanf(" %d %d %d %d %d %d",&han,&lia,&shan,&slia,&ehan,&elia);
		for(int i=1;i<=han;++i){
			cin>>t;
			for(int j=1;j<=lia;++j)
				puzzle[i][j]=t[j-1]-'0';
		}
		w[shan][slia]=1;
		p.push(P(shan,slia));
		while(!p.empty()){
			test=p.front();
			p.pop();
			if(test.first==ehan&&test.second==elia){
				f=true;
				printf("%d\n",w[ehan][elia]);
				break;
			}
			for(int i=0;i<4;++i){
				int nhan=test.first+addlia[i],nlia=test.second+addlia[i];
				if(nhan>0&&nlia>0&&nhan<=han&&nlia<=lia&&puzzle[nhan][nlia]!=1&&w[nhan][nlia]==0){
					p.push(P(test.first+addhan[i],test.second+addlia[i]));
					w[nhan][nlia]=w[test.first][test.second]+1;
				}
			}
		}
		while(!p.empty())
			p.pop();
		if(!f)
			puts("0");
	}
	return 0;
}
