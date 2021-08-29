#include<cstdio>
#include<stack>
using namespace std;

int main(){
	int N,B[1005];
	int cnt;
	stack<int> station;
	while(scanf(" %d",&N)&&N!=0){
		while(scanf(" %d",&B[0])&&B[0]!=0){
			station=stack<int>();
			for(int i=1;i<N;++i)
				scanf(" %d",&B[i]);
			cnt=0;
			for(int A=1;A<=N;++A){
				if(B[cnt]!=A)
					station.push(A);
				else{
					++cnt;
					while(!station.empty()&&station.top()==B[cnt]){
						station.pop();
						cnt++;
					}
				}
			}
			if(station.empty())
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
