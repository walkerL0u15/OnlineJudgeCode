#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int N,c=0;
	char x;
	string sa,sb;
	scanf("%d",&N);
	--N;
	for(int i=0;i<=N;++i){
		scanf(" %c",&x);
		sa+=x;
	}
	for(int i=N;i>=0;--i)
		sb+=sa[i];
	int a=0,b=N;
	while(a<=b){
		if(sa<=sb){
			printf("%c",sa[0]);
			++a;
			sa.erase(0,1);
		}
		else{
			printf("%c",sb[0]);
			--b;
			sb.erase(0,1);
		}
		++c;
		if(c>=80){
			printf("\n");
			c=0;
		}
	}
	return 0;
}