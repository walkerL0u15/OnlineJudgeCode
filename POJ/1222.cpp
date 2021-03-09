#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int C=6,R=5;
int t=1,flip[10][10],c[10][10],d[10][10];
int dr[]={0,1,-1,0,0},dc[]={0,0,0,1,-1};
void add(int r,int c){
    for(int i=0;i<5;++i){
        int ur=r+dr[i],uc=c+dc[i];
        if(ur>=0&&uc>=0) ++flip[ur][uc];
    }
    return;
}
bool cal(){
    for(int i=0;i<R-1;++i)
        for(int j=0;j<C;++j)
            if((c[i][j]+flip[i][j])&1){
                add(i+1,j);d[i+1][j]=true;
            }
    for(int i=0;i<C;++i)
        if((flip[R-1][i]+c[R-1][i])&1)
            return false;
    printf("PUZZLE #%d\n",t);
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j)
            printf("%d ",d[i][j]);
        printf("\n");
    }
    return true;
}

int main(){
    int T;
    bool f;
    scanf(" %d",&T);
    while(t<=T){
        f=false;
        memset(c,0,sizeof(c));
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                scanf(" %d",&c[i][j]);
        for(int i=0;i<(1<<C);++i){
            memset(d,0,sizeof(d));
            memset(flip,0,sizeof(flip));
            for(int j=0;j<C;++j)
                if((i>>j)&1){
                    add(0,j);d[0][j]=true;
                }
            if(cal()) break;
        }
        ++t;
    }
    return 0;
}
