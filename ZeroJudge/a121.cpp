#include<stdio.h>

bool chart[100000002];
void init(){
    chart[1]=true;
    for(int i=3;i<=100000000;i+=2)
        if(!chart[i])
            for(int j=i*3,k=i*2;j<=100000000;j+=k)
                chart[j]=true;
    return;
}

int main(){
    int a,b,ans;
    init();
    while(scanf(" %d %d",&a,&b)==2){
        if(a<=2&&b>=2)  ans=1;
        else  ans=0;
        if(a%2==0)  ++a;
        for(;a<=b;a+=2)
            if(!chart[a])
                ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
