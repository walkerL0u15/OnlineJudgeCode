#include<cstdio>

int main(){
    int N,c;
    char door[1000];
    scanf(" %d %s %d",&N,door,&c);
    for(int i=0;i<N;++i)
        if(i!=c&&door[i]!='C')
            printf("%d ",i+1);
    printf("\n");
    return 0;
}
