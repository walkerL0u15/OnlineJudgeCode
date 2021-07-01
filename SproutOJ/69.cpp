//sprout 69
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MaxN=1e4,MaxM=1e8;

int N,T,K;
ll a[MaxN+10],b[MaxN+10],c[MaxN+10],cpy[MaxN+10];
bool cmp(ll &a,ll &b){
    return a>b;
}
int win(int d){
    for(int i=0;i<N;++i)
        cpy[i]=a[i]+d*b[i];
    sort(cpy,cpy+N,cmp);
    int p=0;
    for(int i=0;i<N;++i)
        if(cpy[p]>c[i])
            ++p;
    return p;
}

int main(){
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d",&N,&K);
        for(int i=0;i<N;++i)
            scanf(" %lld %lld",&a[i],&b[i]);
        for(int i=0;i<N;++i)
            scanf(" %lld",&c[i]);
        sort(c,c+N,cmp);
        ll lb=-1,rb=MaxM+10;
        while(rb-lb>1){
            ll mid=(rb+lb)/2;
            if(win(mid)>=K)
                rb=mid;
            else
                lb=mid;
        }
        if(rb==MaxM+10)
            printf("-1\n");
        else
            printf("%lld\n",rb);
    }
    return 0;
}
