#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define f first
#define s second

int main(){
    int C,L,pl=0,ans=0;
    pair<int,int> cow[5005],sun[5005];
    priority_queue<int,vector<int>,greater<int> > pq;
    scanf(" %d %d",&C,&L);
    for(int i=0;i<C;++i)
        scanf(" %d %d",&cow[i].f,&cow[i].s);
    for(int i=0;i<L;++i)
        scanf(" %d %d",&sun[i].f,&sun[i].s);
    sort(cow,cow+C);
    sort(sun,sun+L);
    int now;
    for(int i=0;i<L;++i){
        while(pl<C&&cow[pl].f<=sun[i].f)
            pq.push(cow[pl++].s);
        while(sun[i].s&&(!pq.empty())){
            now=pq.top();
            pq.pop();
            if(now<sun[i].f)
                continue;
            --sun[i].s;
            ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
