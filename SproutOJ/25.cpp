//sprout 25
#include<cstdio>

struct Node{
	int id;
	Node *next;
	Node(int a,Node *b){
		id=a,next=b;
	}
};
Node *head[105]={NULL},*last[105]={NULL};
Node *newNode;

int main(){
	int N,M,id,s_i,s_j;
	char rec[10];
	scanf(" %d %d",&N,&M);
	while(M--){
		scanf(" %s",rec);
		if(rec[0]=='A'){
			scanf(" %d %d",&s_i,&id);
			newNode=new Node(id,NULL);
			if(head[s_i]==NULL){
				head[s_i]=newNode,last[s_i]=newNode;
			}
			else{
				last[s_i]->next=newNode,last[s_i]=newNode;
			}
		}
		else if(rec[0]=='L'){
			scanf(" %d",&s_i);
			if(head[s_i]==NULL){
				printf("queue %d is empty!\n",s_i);
			}
			else{
				newNode=head[s_i];
				head[s_i]=head[s_i]->next;
				delete newNode;
			}
		}
		else{
			scanf(" %d %d",&s_i,&s_j);
			if(head[s_j]==NULL)
				head[s_j]=head[s_i];
			else
				last[s_j]->next=head[s_i];
			if(head[s_i]!=NULL)
				last[s_j]=last[s_i];
			head[s_i]=NULL;
		}
	}
	for(int i=1;i<=N;++i){
		if(head[i]==NULL)
			printf("queue %d: empty\n",i);
		else{
			printf("queue %d:",i);
			Node *cur=head[i];
			while(head[i]!=NULL){
				printf(" %d",head[i]->id);
				head[i]=head[i]->next;
			}
			printf("\n");
		}
	}
	return 0;
}
