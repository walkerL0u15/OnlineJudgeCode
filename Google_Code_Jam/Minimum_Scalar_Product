#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long
#define MaxN 805

bool cmp(int &a,int &b){
    return a>b;
}

int main()
{
    int T,N;
    int x[MaxN],y[MaxN];
    ll total;
    scanf(" %d",&T);
    for(int Case=1;Case<=T;++Case){
        total=0;
        scanf(" %d",&N);
        for(int i=0;i<N;++i)
            scanf(" %d",&x[i]);
        for(int i=0;i<N;++i)
            scanf(" %d",&y[i]);
        sort(x,x+N);sort(y,y+N,cmp);
        for(int i=0;i<N;++i)
            total+=(ll)x[i]*y[i];
        printf("Case #%d: %lld\n",Case,total);
    }
    return 0;
}
