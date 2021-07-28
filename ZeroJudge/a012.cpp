#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    ll a,b;
    while(scanf(" %lld %lld",&a,&b)==2){
        printf("%lld\n",abs(a-b));
    }
    return 0;
}
