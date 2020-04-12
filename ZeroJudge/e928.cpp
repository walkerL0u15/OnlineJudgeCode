#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int N,M,last;
	int n[101],m[101],ans[300];
	memset(ans,-0,sizeof(ans));
	scanf(" %d",&N);
	for(int i=N;i>=0;--i)
		scanf(" %d",&n[i]);
	scanf(" %d",&M);
	for(int j=M;j>=0;--j)
		scanf(" %d",&m[j]);
	for(int i=N;i>=0;--i)
		for(int j=M;j>=0;--j)
			ans[i+j]+=n[i]*m[j];
	for(int i=250;i>=0;--i)
		if(ans[i]!=0){
			last=i;
			break;
		}
	printf("%d\n",last);
	for(int i=last;i>=0;--i)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}