//sprout 70
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll> > pq;

int main(){
    int N,num;
    while(scanf(" %d",&N)&&N!=0){
        pq=priority_queue<ll,vector<ll>,greater<ll> >();
        while(N--){
            scanf(" %d",&num);
            pq.push((ll)num);
        }
        ll total=0;
        while(pq.size()>1){
            ll a=pq.top();pq.pop();
            ll b=pq.top();pq.pop();
            total+=a+b;
            pq.push(a+b);
        }
        printf("%lld\n",total);
    }
    return 0;
}
