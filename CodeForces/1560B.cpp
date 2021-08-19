#include<cstdio>

int main(){
    int T,a,b,c;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d %d",&a,&b,&c);
        int num=(b-a)*2;
        if(num<0) num=-num;
        if(c>num||a>num||b>num)
            printf("-1\n");
        else{
            if(c+num/2>num)
                printf("%d\n",c-num/2);
            else
                printf("%d\n",c+num/2);
        }
    }
    return 0;
}
