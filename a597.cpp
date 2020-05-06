#include<iostream>
#include<utility>
#include<string.h>
#include<queue>
#define pair<int,int> P;

bool floor[500][500];

int main()
{
	int r,c;
	string s;
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
				
			}
		}
}
