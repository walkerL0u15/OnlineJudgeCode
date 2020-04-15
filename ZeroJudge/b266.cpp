#include<iostream>
#include<string.h>
using namespace std;

int r,c,times;
int block[12][12],turn[12];
void t(){
    int cpy[12][12];
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            cpy[c-1-j][i]=block[i][j];
    int temp=r;r=c;c=temp;
    memcpy(block,cpy,sizeof(block));
    return;
}
void f(){
    int cpy[12][12];
    memcpy(cpy,block,sizeof(cpy));
    for(int i=0;i<r/2;++i)
        for(int j=0;j<c;++j){
            block[i][j]=block[r-i-1][j];
            block[r-i-1][j]=cpy[i][j];
        }
    return;
}

int main()
{
    scanf(" %d %d %d",&r,&c,&times);
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            scanf(" %d",&block[i][j]);
    for(int i=0;i<times;++i)
        scanf(" %d",&turn[i]);
    for(int j=times-1;j>=0;--j){
        if(turn[j]==0){
            t();
        }
        else
            f();
    }
    printf("%d %d\n",r,c);
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j)
            printf("%d ",block[i][j]);
        printf("\n");
    }
    return 0;
}