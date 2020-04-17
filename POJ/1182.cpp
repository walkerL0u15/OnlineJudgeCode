#include<iostream>
using namespace std;

#define Max_N 50000

int par[Max_N*3],dep[Max_N*3];//A:0-N-1 B:N-2N-1 C:2N-3N-1
void init(int n){
	for(int i=0;i<n;++i){
		par[i]=i,dep[i]=0;
	return;
}
bool find(int g)
bool same(int ax,int ay){
	 return find(x)==find(y);
}


int main()
{
	int N,K,x,y,t,ans=0;
	scanf(" %d %d",&N,&K);
	while(K--){
		scanf(" %d %d %d",&t,&x,&y);
		x-=1,y-=1;
		if(x<0||x>=N||y<0||y>=N){
			++ans;
			continue;
		}
		if(t==1){
			
		}
	}
}
