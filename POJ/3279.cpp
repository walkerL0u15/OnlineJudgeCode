#include<cstdio>
#include<cstring>
const int INF=0x3f3f3f3f;

int N,M;
int tile[20][20];
int flip[20][20],ans[20][20];
int tx[]={1,-1,0,0,0};
int ty[]={0,0,1,-1,0};
int C(int i,int j){
    int cnt=0;
    for(int k=0;k<5;++k){
        int rx=j+tx[k],ry=i+ty[k];
        if(rx>=0&&ry>=0&&rx<N&&ry<M) cnt+=flip[rx][ry];
    }
    return cnt;
}

int Find(){
    int cnt,res=0;
    for(int i=0;i<M-1;++i)
        for(int j=0;j<N;++j){
            cnt=C(i,j);
            if((cnt+tile[j][i])&1)
                ++res,flip[j][i+1]=true;
        }
    for(int j=0;j<N;++j){
        cnt=C(M-1,j);
        if((cnt+tile[j][M-1])&1)
            return INF;
    }
    return res;
}

int main(){
    int r,m=INF;
    scanf(" %d %d",&N,&M);
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            scanf(" %d",&tile[i][j]);
    for(int i=0;i<(1<<N);++i){
        memset(flip,0,sizeof(flip));
        for(int j=0;j<N;++j)
            flip[j][0]=(i>>j)&1;
        r=Find();
        if(r<m){
            m=r;
            memcpy(ans,flip,sizeof(flip));
        }
    }
    if(m==INF){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
