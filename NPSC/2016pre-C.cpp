#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

bool cmp(int a,int b){
    return a>b;
}

int w[1000005],d[1000005];

int main(){
    int N,D;

    scanf(" %d %d",&N,&D);
    for(int i=0;i<N;++i)
        scanf(" %d",&w[i]);
    for(int j=0;j<D;++j)
        scanf(" %d",&d[j]);
    ll ans=0;
    sort(w,w+N,cmp);
    sort(d,d+D);
    for(int i=0;i<N;++i)
        ans+=w[i]*d[i];
    printf("%lld\n",ans);
    return 0;
}
