#include<cstdio>
#include<cstring>

int N,M;
int tile[20][20];
int flip[20][20],ans[20][20];

int main(){
    int res=-1;
    scanf(" %d %d",&N,&M);
    for(int i=0;i<=N;++i)
        for(int j=0;j<=M;++j)
            scanf(" %d",&tile[i][j]);
    for(int i=0;i< 1<<N;++i){
        memset(flip,0,sizeof(flip));
        for(int j=0;j<N;++j)
            flip[0][j]=i>>j;
        int m=calc();
        if(m>=0&&(res<0||res>m)){
            memcpy(ans,flip,sizeof(flip));
            res=m;
        }
    }
    if()
}
