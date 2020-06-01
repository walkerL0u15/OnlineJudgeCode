#include<string>
#include<iostream>
#include<stdio.h>
#include<set>//change to map
using namespace std;

int main()
{
	int N,M,ans=0;
	bool flag;
	string color[200000];
	scanf(" %d %d",&M,&N);
	for(int i=0;i<N;++i)
		cin>>color[i];
	for(int i=0;i+M-1<N;++i){
		set<> s;
		flag=true;
		for(int j=i;j<i+M;++j){
			if(s.find(color[j])==s.end())
				s.insert(color[j]);
			else{
				flag=false;
				break;
			}
		}
		if(flag) ++ans;
	}
	printf("%d",ans);
	return 0;
}
