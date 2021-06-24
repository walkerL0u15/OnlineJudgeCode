//sprout 48
#include<cstdio>

struct Node{
    int num;
    Node *lchild=NULL,*rchild=NULL;
};
int x;
Node *newNode=NULL,*f=NULL;
void in(int k,Node* now){
    if(k>now->num){
        if(now->rchild==NULL)
            now->rchild=newNode;
        else
            in(k,now->rchild);
    }
    else{
        if(now->lchild==NULL)
            now->lchild=newNode;
        else
            in(k,now->lchild);
    }
    return;
}
void print(Node *now){
    if(now->lchild!=NULL)
        print(now->lchild);
    if(now->rchild!=NULL)
        print(now->rchild);
    printf("%d\n",now->num);
    return;
}

int main(){
    scanf(" %d",&x);
    f=new Node,f->num=x;
    while(scanf(" %d",&x)!=EOF){
        newNode=new Node,newNode->num=x;
        in(x,f);
    }
    print(f);
    return 0;
}
