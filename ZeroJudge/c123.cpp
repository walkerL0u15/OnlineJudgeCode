#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

int main()
{
	int N,c;
	stack<int>station;
	while(scanf("%d",&N)&&N!=0){
		station=stack<int>();
		int to[N];
		while(scanf("%d",&to[0])&&to[0]!=0){
			c=0;
			for(int i=1;i<N;++i)
				scanf("%d",&to[i]);
			for(int i=1;i<=N;++i){
				if(i==to[c]){
					++c;
					while(!station.empty()&&station.top()==to[c]){
						station.pop();
						++c;
					}
				}
				else
					station.push(i);
			}
			printf("%s\n",(c==N?"Yes":"No"));
		}
		printf("\n");
	}
	return 0;
}