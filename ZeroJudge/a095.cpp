#include<stdio.h>

int main()
{
    int N,M;
    while(scanf(" %d %d",&M,&N)==2)
        printf("%d\n",(N==M?N:N+1));
    return 0;
}
