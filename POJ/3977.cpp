//XXX poj是c++98 abs沒有long long
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define abs(x) ((x) >= 0 ? (x) : -(x))

ll num[40];
map<ll,ll>::iterator it;
map<ll,ll> m;

int main(){
    int N;
    while(scanf(" %d",&N)&&N!=0){
        m.clear();
        for(int i=0;i<N;++i)
            scanf(" %lld",&num[i]);
        ll sum,cnt;
        ll ans=abs(num[0]),au=1;
        for(int i=1;i<(1<<(N/2));++i){
            sum=0,cnt=0;
            for(int j=0;j<N/2;++j)
                if((i>>j)&1){
                    sum+=num[j],++cnt;
                }
            ll suma=abs(sum);
            if(suma<ans||(suma==ans&&cnt<au))
                ans = suma, au = cnt;
            if(m[sum]) m[sum]=min(m[sum],cnt);
            else m[sum]=cnt;
        }
        for(int i=1;i<(1<<(N-N/2));++i){
            sum=0,cnt=0;
            for(int j=0;j<N-N/2;++j)
                if((i>>j)&1){
                    sum+=num[N/2+j],++cnt;
                }
            ll suma=abs(sum),t;
            if(suma<ans||(suma==ans&&cnt<au))
                ans = suma, au = cnt;
            it=m.lower_bound(-sum);
            if(it!=m.end()) {
                suma = abs(sum + it->f), t = cnt + it->s;
                if (suma < ans || (suma == ans && t < au))
                    ans = suma, au = t;
            }
            if(it!=m.begin()){
                --it;
                suma=abs(sum+it->f),t=cnt+it->s;
                if(suma<ans||(suma==ans&&t<au))
                    ans = suma, au = t;
            }
        }
        printf("%lld %lld\n",ans,au);
    }
    return 0;
}
