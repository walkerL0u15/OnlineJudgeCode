#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

struct C{
    double t,e;
}cows[100005];
bool cmp(C a,C b){
    return a.t/a.e<b.t/b.e;
}

int main(){
    ll ans=0,flower=0,N;
    scanf(" %lld",&N);
    for(int i=0;i<N;++i){
        scanf(" %lf %lf",&cows[i].t,&cows[i].e);
        flower+=(int)cows[i].e;
    }
    sort(cows,cows+N,cmp);
    for(int i=0;i<N;++i){
        flower-=(int)cows[i].e;
        ans+=flower*(int)cows[i].t;
    }
    printf("%lld\n",ans*2);
    return 0;
}
