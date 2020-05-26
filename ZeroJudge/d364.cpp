#include<stdio.h>

int S,t,num[31];
bool flag;
bool gcd(int a,int b){
    int temp;
    while(b!=0){
        temp=a%b;
        a=b;
        b=temp;
    }
    if(a==1)
        return true;
    return false;
}
void dfs(int use,int left){
    if(use>=t+1){
        if(left==0){
            for(int i=1;i<use;++i)
                printf("%d ",num[i]);
            puts("");
        }
        return;
    }
    for(int i=num[use-1];i<=left;++i){
        flag=true;
        for(int j=1;j<use;++j)
            if(!gcd(i,num[j])){
                flag=false;
                break;
            }
        if(flag){
            num[use]=i;
            dfs(use+1,left-i);
        }
    }
    return;
}

int main()
{
    int N;
    num[0]=1;
    while(scanf(" %d",&N)!=EOF){
        for(int i=1;i<=N;++i){
            scanf(" %d %d",&S,&t);
            printf("Case %d:\n",i);
            dfs(1,S);
        }
    }
    return 0;
}
