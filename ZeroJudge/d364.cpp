#include<iostream>
using namespace std;

int ans[32];
int N,s,t;
bool gcd(int a,int b){
	while((a%=b)!=0&&(b%=a)!=0);
	return ((a==1||b==1)?true:false);
}
void check(int counter,int left,int i){
	if(left<ans[counter-1])
		return;
	else if(counter>=t&&gcd(ans[counter-1],left)){
		for(int j=1;j<t;++j)
			printf("%d ",ans[j]);
		printf("%d\n",left);
		return;
	}
	for(;i<=left;++i)
		if(gcd(i,ans[counter-1])){
			ans[counter]=i;
			check(counter+1,left-i,i);
		}
	return;
}


int main()
{
	scanf("%d",&N);
	ans[0]=1;
	for(int i=1;i<=N;++i){
		scanf("%d%d",&s,&t);
		printf("Case %d:\n",i);
		check(1,s,1);
	}
	return 0;
}