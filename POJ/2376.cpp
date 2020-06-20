#include<stdio.h>
#include<string.h>

int cows[1000005];

int main()
{
    int N,T,cnt=1,s,e;
    scanf(" %d %d",&N,&T);
    memset(cows,0,sizeof(cows));
    for(int i=0;i<N;++i){
        scanf(" %d %d",&s,&e);
        if(e>cows[s]) cows[s]=e;
    }
    if(cows[1]==0){
        puts("-1");
        return 0;
    }
    int c=cows[1],ch;
    int i=2;
    while(i<=T&&c<T){
        ch=c;
        for(;i<=c+1;++i)
            if(cows[i]>ch) ch=cows[i];
        if(c==ch) break;
        c=ch,++cnt;
    }
    if(c>=T)
        printf("%d\n",cnt);
    else
        puts("-1");
    return 0;
}
