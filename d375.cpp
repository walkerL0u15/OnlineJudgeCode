#include<iostream>
#include<string.h>
using namespace std;

int T,l,N,num[25];
bool used[25],r;
bool rect(int total){
	if(total==l)
		return true;
	else if(total>l)
		return false;
	for(int i=0;i<N;++i){
		if(used[i]==true)
			continue;
		used[i]=true;
		if(rect(total+num[i]))
			return true;
		used[i]=false;
	}
	return false;
}

int main()
{
	scanf(" %d",&T);
	while(T--){
		r=true;
		memset(used,0,sizeof(used));
		l=0;
		scanf(" %d",&N);
		for(int i=0;i<N;++i){
			scanf(" %d",&num[i]);
			l+=num[i];
		}
		if(l%4!=0){
			puts("no");
			continue;
		}
		l/=4;
		for(int i=0;i<3;++i)
			if(!rect(0)){
				r=false;
				break;
			}
		if(r)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
