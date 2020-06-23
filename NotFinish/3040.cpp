#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;
#define ll long long
#define P pair<int,int>
#define INF 200000000

bool cmp(P &a,P &b){return a.first>b.first;}

int main()
{
	int N,C,need[22],temp;
	ll week=0,add=0;
	P coin[22];
	bool flag;
	scanf(" %d %d",&N,&C);
	for(int i=0;i<N;++i){
		scanf(" %d %d",&coin[i].first,&coin[i].second);
		if(coin[i].first>=C) week+=coin[i].second,coin[i].second=0;
	}
	sort(coin,coin+N,cmp);
	//////////////////////////////////////////////////////////////////////
	while(true){
		temp=C;
		flag=true;
		//close to C but <=C
		memset(need,false,sizeof(need));
		for(int i=N-1;i>=0;--i){
			if(coin[i].second>=0){
				need[i]=min(temp/coin[i].first,coin[i].second);
				temp-=need[i]*coin[i].first;
			}
			else if(temp<=0){
				flag=false;
				break;
			}
		}
		//fill until >=C
		for(int i=0;i<N;++i){
			if(need[i]<coin[i].second){
				int t=min(temp/coin[i]+1,coin[i].second-need[i]);
				need+=t;
				temp-=t*coin[i].first;
			}
			else if(temp<=0){
				flag=false
				break;
			}
		}
		//minus
		int num=INF;
		
	}
}
