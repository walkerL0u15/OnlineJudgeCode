#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N;
	queue<int> card;
	while(scanf("%d",&N)&&N!=0){
		card=queue<int>();
		if(N==1){
			printf("Discarded cards:\nRemaining card: 1\n");
			continue;
		}
		for(int i=1;i<=N;++i)
			card.push(i);
		printf("Discarded cards:");
		while(card.size()>2){
			printf(" %d,",card.front());
			card.pop();
			card.push(card.front());
			card.pop();
		}
		printf(" %d",card.front());
		card.pop();
		printf("\nRemaining card: %d\n",card.front());
	}
	return 0;
}