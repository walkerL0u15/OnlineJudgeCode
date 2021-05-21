//sprout 36
#include<cstdio>
#include<stack>
using namespace std;

int main(){
	int N,a,num;
	stack<int> s;
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
				printf("%d\n",s.top());
				s.pop();
			}
		}
	}
	return 0;
}
