#include<cstdio>
typedef long long ll;

int main(){
    ll n,m,a;
    scanf(" %lld %lld %lld",&n,&m,&a);
    n=(n%a==0?0:1)+n/a;
    m=(m%a==0?0:1)+m/a;
    printf("%lld\n",n*m);
    return 0;
}
