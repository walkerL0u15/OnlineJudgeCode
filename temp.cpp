#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0);

struct Node{
    int idx;
    Node *nxt=NULL;
    Node(int idx_,Node *nxt_){
        idx=idx_,nxt=nxt_;
    }
};
Node *head[105]={NULL},*last[105]={NULL};
Node *newNode;

int main(){
    int N,M;
    string cmd;
    cin>>N>>M;
    while(M--){
        cin>>cmd;
        if(cmd[0]=='A'){
            int i,id;
            cin>>i>>id;
            newNode=new Node(id,last[i]);
            if(head[i]==NULL){
                head[i]=newNode,last[i]=newNode;
            }
            else{
                last[i]->nxt=newNode,last[i]=newNode;
            }
        }
        else if(cmd[0]=='L'){
            int i;
            cin>>i;
            if(head[i]==NULL){
                cout<<"queue "<<i<<" is empty!\n";
            }
            else{
                newNode=head[i];
                head[i]=head[i]->nxt;
                delete newNode;
            }
        }
        else{
            int i,j;
            cin>>i>>j;
            if(head[j]==NULL)
                head[j]=head[i];
            else
                last[j]->nxt=head[i];
            if(!(head[i]==NULL))
                last[j]=last[i];
            head[i]=NULL,last[j]=NULL;
        }
    }
    for(int i=1;i<=N;++i){
        Node *now=head[i];
        cout<<"queue "<<i<<":";
        if(head[i]==NULL){
            cout<<"empty!\n";
        }
        else{
            while(now!=NULL){
                cout<<" "<<now->idx;
                now=now->nxt;
            };
            cout<<"\n";
        }
    }
}
