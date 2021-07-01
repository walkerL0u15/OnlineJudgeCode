//sprout 62
#include<cstdio>
#include<cstring>

char lable[11][11];
bool row[11][11],col[11][11],block[4][4][11];
void input(int r,int c,int n,bool b){
    if(n=='.'-'0') return;
    row[r][n]=b;
    col[c][n]=b;
    block[r/3][c/3][n]=b;
    return;
}
bool dfs(int p){
    if(p>=81) 
        return true;
    int r=p/9,c=p%9;
    if(lable[r][c]!='.'){       
        if(dfs(p+1))
            return true;
        return false;
    }
    for(int i=1;i<=9;++i){
        if(row[r][i]||col[c][i]||block[r/3][c/3][i])
            continue;
        lable[r][c]=i+'0';
        input(r,c,i,true);
        if(dfs(p+1))
            return true;
        input(r,c,i,false);
        lable[r][c]='.';
    }
    return false;
}

int main(){
    while((lable[0][0]=getchar())!='e'){
        bool reb=true;
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(block,false,sizeof(block));
        input(0,0,lable[0][0]-'0',true);
        for(int i=0;i<9;++i){
            for(int j=(i==0?1:0);j<9;++j){
                lable[i][j]=getchar();
                if(lable[i][j]!='.'){
                    int x=lable[i][j]-'0';
                    if(row[i][x]||col[j][x]||block[i/3][j/3][x])
                        reb=false;
                }
                input(i,j,lable[i][j]-'0',true);
            }
        }
        getchar();
        if(!reb||!dfs(0)){
            printf("No solution.\n");
            continue;
        }
        for(int i=0;i<9;++i)
            printf("%s",lable[i]);
        printf("\n");
    }
    return 0;
}
