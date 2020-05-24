#include<stdio.h>
#include<string.h>

int N;
bool used[9];
char s[9];
void password(int time){
    if(time>N){
        for(int i=1;i<=N;++i)
            printf("%d",s[i]);
        puts("");
        return;
    }
    for(int i=N;i>=1;--i)
        if(used[i]==0){
            used[i]=1;
            s[time]=i;
            password(time+1);
            used[i]=0;
        }
    return;
}

int main()
{
    while(scanf(" %d",&N)==1){
        memset(used,0,sizeof(used));
        password(1);
    }
    return 0;
}
