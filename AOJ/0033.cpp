#include<stdio.h>

int main()
{
    int T;
    int ball,b,c;
    bool flag;
    scanf(" %d",&T);
    while(T--){
        b=-1,c=-1;
        flag=true;
        for(int i=0;i<10;++i){
            scanf(" %d",&ball);
            if(ball<b&&ball<c)
                flag=false;
            else if(b<ball)
                b=ball;
            else
                c=ball;
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
