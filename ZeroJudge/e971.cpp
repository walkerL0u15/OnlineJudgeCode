#include<iostream>
using namespace std;

int main()
{
    int r,c,color[101][101],f=105;
    bool t;
    scanf(" %d %d",&r,&c);
    for(int i=0;i<r;++i){
        t=false;
        for(int j=0;j<c;++j)
            scanf(" %d",&color[i][j]);
        for(int j=0;j<c;++j)
            if(color[i][j]==1){
                f=j;
                break;
            }
        for(int j=f+1;j<c;++j)
            if(color[i][j]==1){
                t=!t;
                if(t)
                    for(int k=f+1;k<j;++k)
                        color[i][k]=1;
                else
                    f=j;
            }
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j)
            printf("%d ",color[i][j]);
        putchar('\n');
    }
    return 0;
}