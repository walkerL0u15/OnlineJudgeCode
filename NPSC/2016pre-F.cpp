#include<cstdio>

int main(){
    int Y,M,D,W,t;
    scanf(" %d %d %d %d %d",&Y,&M,&D,&W,&t);
    if(W<=5){
        if(t==1)
            printf("happy\n");
        else
            printf("unhappy\n");
    }
    else{
        if(t==1)
            printf("unhappy\n");
        else
            printf("happy\n");
    }
    return 0;
}
