#include<cstdio>
int b[15][15];

int r[]={1,-1,0,0};
int c[]={0,0,1,-1};
int main(){
    int R,C;
    scanf(" %d %d",&R,&C);
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            scanf(" %d",&b[i][j]);
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(b[i][j]!=0)
                printf("%d ",b[i][j]);
            else{
                int t=0,cnt=0;
                for(int k=0;k<4;++k)
                    if(i+r[k]>=0&&i+r[k]<R&&j+c[k]>=0&&j+c[k]<C&&b[i+r[k]][j+c[k]]!=0){
                        cnt++,t+=b[i+r[k]][j+c[k]];
                    }
                if(cnt==0)
                    printf("0 ");
                else
                    printf("%d ",t/cnt);
            }
        }
        printf("\n");
    }
}
