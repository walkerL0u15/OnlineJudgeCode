//sprout 19
#include<cstdio>
#include<stack>
using namespace std;

int main(){
	int C,N,A,B;
	scanf(" %d",&C);
	while(C--){
		stack<int> station;
		scanf(" %d",&N);
		A=1;
		for(int i=0;i<N;++i){
			scanf(" %d",&B);
			if(!station.empty()&&station.top()==B)
				station.pop();
			else{
				while(A<=N&&A!=B){
					station.push(A);++A;
				}
				++A;
			}
		}
		if(station.empty()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
