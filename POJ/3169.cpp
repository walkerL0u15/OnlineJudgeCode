#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int AL[10005],BL[10005],DL[10005];
int AD[10005],BD[10005],DD[10005];

int main(){
    int N,ML,MD;
    int d[10005];
    scanf(" %d %d %d",&N,&ML,&MD);
    for(int i=0;i<ML;++i)
        scanf(" %d %d %d",&AL[i],&BL[i],&DL[i]);
    for(int i=0;i<MD;++i)
        scanf(" %d %d %d",&AD[i],&BD[i],&DD[i]);
    fill(d,d+10005,INF);
    d[1]=0;
    for(int k=0;k<N;++k){
        for(int i=N;i>=2;--i)
            if(d[i]<INF)
                d[i-1]=min(d[i-1],d[i]);
        for(int i=0;i<ML;++i)
            if(d[AL[i]]<INF)
                d[BL[i]]=min(d[BL[i]],d[AL[i]]+DL[i]);
        for(int i=0;i<MD;++i)
            if(d[BD[i]]<INF)
                d[AD[i]]=min(d[AD[i]],d[BD[i]]-DD[i]);
    }
    if(d[1]<0)
        puts("-1");
    else if(d[N]==INF)
        puts("-2");
    else
        printf("%d\n",d[N]);
    return 0;
}
