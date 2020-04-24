#include<iostream>
#include<stdio.h>
using namespace std;

struct str{int x,y,z;};
str cube[205];
int n,h,ans;
void cal(int total,int c){
	if(total>h)
		return;
	if(c==n){
		if(total>ans)
			ans=total;
		return;
	}
	cal(total+cube[c].x,c+1);
	cal(total+cube[c].y,c+1);
	cal(total+cube[c].z,c+1);
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		ans=0;
		scanf("%d%d",&n,&h);
		for(int j=0;j<n;++j)
			scanf("%d%d%d",&cube[j].x,&cube[j].y,&cube[j].z);
		cal(0,0);
		if(ans==0)
			printf("no solution\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}