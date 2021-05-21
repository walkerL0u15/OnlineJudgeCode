//sprout 37
#include<cstdio>
#include<queue>
using namespace std;

int main(){
	int N,a,num;
	queue<int> s;
	scanf(" %d",&N);
	while(N--){
		scanf(" %d",&a);
		if(a==1){
			scanf(" %d",&num);
			s.push(num);
		}
		else{
			if(s.empty())
				printf("empty!\n");
			else{
				printf("%d\n",s.front());
				s.pop();
			}
		}
	}
	return 0;
}
