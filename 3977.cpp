#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

ll a[1<<18];
int N;
ll num[36],ans=1e17,ansu;
void cal(ll sum){

}

int main(){
    scanf(" %d",&N);
    for(int i=0;i<N;++i)
        scanf(" %lld",&num[i]);
    for(ll i=0;i<1<<(N/2);++i){//mei ji
        a[i]=0;
        for(int j=0;j<N/2;++j)
            if(i>>j&1){
                a[i]+=num[j];
            }
    }
    sort(a,a+(1<<(N/2)),)
    ll sum=0;
    for(ll i=0;i<1<<(N-N/2);++i){
        sum=0;
        for(int j=0;j<(N-N/2);++j)
            if(i>>j&1){
                sum+=num[N/2+j];
            }
        cal(sum);
    }
    printf("%lld %lld\n",ans,ansu);
    return 0;
}
