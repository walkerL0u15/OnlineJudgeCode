#include<cstdio>

int k[1005];

int main(){
    int i=1,cnt=1;
    while(cnt<=1000){
        if(i%3!=0&&i%10!=3)
            k[cnt++]=i;
        ++i;
    }
    int T,num;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d",&num);
        printf("%d\n",k[num]);
    }
    return 0;
}
