#include<cstdio>

int b[10][10],cnt=0;
bool r[10][10]={0},c[10][10]={0},nine[4][4][10]={0};
void dfs(int m){
    if(m>=9*9){
        ++cnt;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j)
                printf("%d ",b[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }
    int row=m/9,col=m%9;
    if(b[row][col]==0){
        for(int i=1;i<=9;++i)
            if(!r[row][i]&&!c[col][i]&&!nine[row/3][col/3][i]){
                r[row][i]=true,c[col][i]=true;
                nine[row/3][col/3][i]=true;
                b[row][col]=i;
                dfs(m+1);
                r[row][i]=false,c[col][i]=false;
                nine[row/3][col/3][i]=false;
            }
        b[row][col]=0;
    }
    else
        dfs(m+1);
    return;
}

int main(){
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j){
            scanf(" %d",&b[i][j]);
            r[i][b[i][j]]=true;
            c[j][b[i][j]]=true;
            nine[i/3][j/3][b[i][j]]=true;
        }
    dfs(0);
    printf("there are a total of %d solution(s).\n",cnt);
    return 0;
}
