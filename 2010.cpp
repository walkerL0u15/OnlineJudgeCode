#include<cstdio>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct Cal{
    int sc,f;
}c[(int)1e5+5];
int N,C,F;
bool cmp(Cal a,Cal b){
    if(a.sc==b.sc)
        return a.f<b.f;
    return a.sc<b.sc;
}
bool cal(int x){
    ll total=c[x].f;
    priority_queue<P,vector<P>,greater<P> > pq;
    for(int i=0;i<x;++i)
        pq.push(P(c[i].f,i));
    for(int i=x+1;i<C;++i)
        pq.push(P(c[i].i));
    int low=0,high=0;
    while(low<N/2&&high<N/2){

    }
}

int main(){
    scanf(" %d %d %d",&N,&C,&F);
    for(int i=0;i<C;++i)
        scanf(" %d %d",&c[i].sc,&c[i].f);
    sort(c,c+C,cmp);
    int l=-1,r=C+1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(cal(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%d\n",c[l].sc);
    return 0;
}
