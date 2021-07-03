//sprout 59
#include<cstdio>
#include<algorithm>
using namespace std;

int p=0,tree[(int)1e6+10];
void push(int n){
    tree[++p]=n;
    int x=p;
    while(x>1){
        if(tree[x]<tree[x>>1])
            swap(tree[x],tree[x>>1]);
        else
            break;
        x>>=1;
    }
    return;
}
void pop(){
    if(p==0){
        printf("empty!\n");
        return;
    }
    else
        printf("%d\n",tree[1]);
    tree[1]=tree[p--];
    int x=1;
    while(x*2<=p){
        if(x*2+1>p){
            if(tree[x]>tree[x*2])
                swap(tree[x],tree[x*2]);
            break;
        }
        else{
            int small;
            if(tree[x*2]<tree[x*2+1])
                small=x*2;
            else
                small=x*2+1;
            if(tree[x]>tree[small]){
                swap(tree[x],tree[small]);
                x=small;
            }
            else
                break;
        }
    }
    return;
}

int main(){
    int T,d,n;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d",&d);
        if(d==1){
            scanf(" %d",&n);
            push(n);
        }
        else{
            pop();            
        }
    }
    return 0;
}
