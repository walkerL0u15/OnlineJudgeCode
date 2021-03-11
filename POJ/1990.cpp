#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define x first
#define vol second

ll N;
P cows[20005];
ll bitx[20005]={0};
ll bitn[20005]={0};
ll sum(ll bit[],int i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll bit[],int i,int x){
    while(i<=20000){
        bit[i]+=x;
        i+=i&-i;
    }
    return;
}
bool cmp(P a,P b){
    return a.vol<b.vol;
}

int main(){
    scanf(" %d",&N);
    for(int i=0;i<N;++i)
        scanf(" %lld %lld",&cows[i].vol,&cows[i].x);
    sort(cows,cows+N,cmp);
    ll res=0,total=0;
    for(int i=0;i<N;++i){
        res+=(total-sum(bitx,cows[i].x)-sum(bitx,cows[i].x-1)+(sum(bitn,cows[i].x-1)+sum(bitn,cows[i].x)-i)*cows[i].x)*cows[i].vol;
        add(bitx,cows[i].x,cows[i].x);add(bitn,cows[i].x,1);
        total+=cows[i].x;
    }
    printf("%lld\n",res);
}
