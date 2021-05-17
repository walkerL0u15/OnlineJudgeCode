//zj c074
#include<cstdio>
using namespace std;

int N,num[16],stack[10];
void dfs(int cnt,int last){
    if(cnt>=6){
        printf("%d",stack[0]);
        for(int i=1;i<6;++i)
            printf(" %d",stack[i]);
        printf("\n");
        return;
    }
    else{
        for(int i=last+1;i<=N;++i){
            stack[cnt]=num[i];
            dfs(cnt+1,i);
        }
    }
    return;
}

int main(){
    bool c=false;
    while(scanf(" %d",&N)&&N!=0){
        if(c)
            printf("\n");
        else
            c=true;
        for(int i=1;i<=N;++i)
            scanf(" %d",&num[i]);
        dfs(0,0);
    }
    return 0;
}
