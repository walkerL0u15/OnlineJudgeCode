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
	/////////////////////////calcutlate
	while(true){
		temp=C;
		flag=true;
		memset(need,0,sizeof(need));
		//add until <=C
		for(int i=0;i<N;++i){
			if(coin[i].second>=0){
				need[i]=min(temp/coin[i].first,coin[i].second);
				temp-=need[i]*coin[i].first;
			}
			else if(temp<=0)
				break;
		}
		//add to >=C
		if(temp>0)
			for(int i=N-1;i>=0;--i)
				if(coin[i].second-need[i]>0){
					++need[i];
					temp-=coin[i].first;
					break;
				}
		if(temp>0) break;
		//add up
		int num=INF;
		for(int i=0;i<N;++i)
			if(need[i]!=0)
				num=min(num,coin[i].second/need[i]);
		week+=num;
		for(int i=0;i<N;++i)
			coin[i].second-=need[i]*num;
	}
	printf("%lld\n",week);
	return 0;
}
