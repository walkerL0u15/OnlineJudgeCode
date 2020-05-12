#include<iostream>
#include<utility>
#include<string.h>
#include<queue>
#define pair<int,int> P;

bool floor[500][500];

int main()
{
	int r,c;
	int r[4]={1,0,-1,0};
	int c[4]={0,-1,0,1};
	string s;
	P t;
	queue<P> b;
	memset(floor,false,sizeof(floor));
	scanf(" %d %d",&r,&c);
	for(int i=0;i<r;++i){
		cin>>s;
		for(int j=0;j<c;++j)
			if(s[j]=='J')
				floor[i][j]=true;
	}
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j){
			if(floor[i][j])
				b.push(P(i,j));
			while(!b.empty()){
				t=b.front();
				if(floor[t.first][t.second]==false||t.first>=r||t.second>=c){
					b.pop();
					continue;
				}
				floor[t.first][t.second]=false;
			}
		}
}
