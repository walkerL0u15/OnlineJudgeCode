//2011senior-F田忌賽馬.cpp
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f,MaxN=10000;
typedef long long ll;

int T,N,K;
ll a[MaxN+5],b[MaxN+5],c[MaxN+5];
ll h[MaxN+5];
bool cmp(ll x,ll y){
    return x>y;
}

int main(){
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d",&N,&K);
        for(int i=0;i<N;++i)
            scanf(" %d %d",&a[i],&b[i]);
        for(int i=0;i<N;++i)
            scanf(" %d",&c[i]);
        sort(c,c+N);
        int l=0,r=1e8,M=INF;
        while(l<=r){
            ll mid=l+(r-l)/2;
            for(int i=0;i<N;++i)
                h[i]=a[i]+b[i]*mid;
            sort(h,h+N,cmp);
            int cnt=0;
            for(int i=N-1;i>=0;--i){
                if(h[cnt]>c[i]){
                    ++cnt;
                    if(cnt>=K) break;
                }
            }
            if(cnt>=K){
                M=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(M==INF)
            printf("-1\n");
        else
            printf("%d\n",M);
    }
    return 0;
}
