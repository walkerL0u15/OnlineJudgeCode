#include<stdio.h>
#include<iostream>
#include<bitset>
using namespace std;

int r,c,m=0;
bitset<10000> b[10];
void dfs(int time){
	if(time==r){
		int t=0;
		for(int i=0;i<r;++i){
			int tsum=0;
			for(int j=0;j<c;++j)
				tsum+=b[i][j];
			t+=max(tsum,c-tsum);
		}
		m=max(m,t);
		return;
	}
	dfs(time+1);
	for(int i=0;i<c;++i)
		b[time][i]=!b[time][i];
	dfs(time+1);
	return;
}

int main()
{
	int in;
	while(scanf(" %d %d",&r,&c)==2&&r!=0){
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j){
				scanf(" %d",&in);
				b[i][j]=in;
			}
		dfs(0);
		printf("%d\n",m);
	}
	return 0;
}
