#include<stdio.h>
#include<string.h>

int main(){
    int N,num=1,sum[1000005];
    scanf(" %d",&N);
    memset(sum,0,sizeof(sum));
    sum[0]=1;
    while(num<=N){
        for(int i=num;i<=N;++i)
            sum[i]=(sum[i]+sum[i-num])%1000000000;
        num<<=1;
    }
    printf("%d\n",sum[N]);
    return 0;
}
