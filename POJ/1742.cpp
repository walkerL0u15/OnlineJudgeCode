#include<cstdio>
#include<cstring>

int way[(int)1e5+10];
int v[105],a[105];

int main(){
    int N,M;
    while(scanf(" %d %d",&N,&M)==2&&N!=0){
        memset(way,-1,sizeof(way));
        way[0]=0;
        for(int i=0;i<N;++i)
            scanf(" %d",&v[i]);
        for(int i=0;i<N;++i)
            scanf(" %d",&a[i]);
        for(int i=0;i<N;++i) {
            for (int j = 0; j <= M; ++j) {
                if (way[j] >= 0)
                    way[j] = a[i];
                else if (j - v[i] >= 0 && way[j - v[i]] > 0)
                    way[j] = way[j - v[i]] - 1;
            }
        }
        int res=0;
        for(int i=1;i<=M;++i)
            if(way[i]>=0){
                ++res;
            }
        printf("%d\n",res);
    }
    return 0;
}
