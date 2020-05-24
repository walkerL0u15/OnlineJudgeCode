#include<stdio.h>

int main()
{
    int a,b,t;
    while(scanf(" %d %d",&a,&b)!=EOF){
        if(b>a) t=a,a=b,b=t;
        while(b!=0)
            t=b,b=a%b,a=t;
        printf("%d\n",a);
    }
    return 0;
}
