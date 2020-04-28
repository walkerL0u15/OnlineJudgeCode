#include<iostream>
using namespace std;

int main()
{
	bool a;
	int N,c;
	while(scanf(" %d",&N)!=EOF){
		a=true;
		c=1;
		for(int c=1;c<=N*N;c+=N){
			if(a)
				for(int j=c;j<c+N;++j)
					printf("%d ",j);
			else
				for(int j=c+N-1;j>=c;--j)
					printf("%d ",j);
			puts("");
			a=!a;
		}
		puts("");
	}
}
