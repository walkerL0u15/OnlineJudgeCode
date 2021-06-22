//sprout 21
#include<cstdio>
#include<algorithm>
using namespace std;
const int MaxN=1e5;

struct Node{
	int num;
	Node *next,*pre;
}a[MaxN+5];
int N,M,amount;
void rush(int n){
	if(a[n].pre==&a[0])
		return;
	Node *b=a[n].pre,*c=&a[n];
	b->pre->next=c,c->next->pre=b;
	b->next=c->next,c->pre=b->pre;
	b->pre=c,c->next=b;
	return;
}
void attacked(int d){
	--amount;
	a[d].pre->next=a[d].next;
	a[d].next->pre=a[d].pre;
	return;
}

int main(){
	int dir,p;
	scanf(" %d %d",&N,&M);
	amount=N;
	a[0].next=&a[1];
	for(int i=1;i<=N;++i)
		a[i].num=i,a[i].next=&a[i+1],a[i].pre=&a[i-1];
	while(M--){
		scanf(" %d %d",&dir,&p);
		if(dir==1)
			rush(p);
		else
			attacked(p);
	}
	Node *cur=a[0].next;
	for(int i=0;i<amount-1;++i){
		printf("%d ",cur->num);
		cur=cur->next;
	}
	printf("%d\n",cur->num);
	return 0;
}
