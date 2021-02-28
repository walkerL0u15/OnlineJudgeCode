#include<cstdio>
typedef long long ll;

ll N,M;
ll cal(ll i,ll j){
    return i*(i+1e5)+j*(j-1e5)+i*j;
}
bool C(ll x){
    ll sum=0;
    for(ll j=1;j<=N;++j){
        ll l=0,r=N+1;//N很小
        while(r-l>1){
            ll mid=(l+r)/2;
            if(cal(mid,j)>=x)
                r=mid;
            else
                l=mid;
        }
        sum+=l;
    }
    return sum>=M;
}

int main(){
    int T;
    scanf(" %d",&T);
    while(T--){
        scanf(" %lld %lld",&N,&M);
        ll l=-1e5*N,r=3*N*N+1e5*N;
        while(r-l>1){
            ll mid=(l+r)/2;
            if(C(mid))
                r=mid;
            else
                l=mid;
        }
        printf("%lld\n",l);
    }
    return 0;
}
