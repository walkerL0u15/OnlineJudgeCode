#include<cstdio>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
#define sc first
#define f second
#define INF 0x3f3f3f3f
typedef pair<int,int> P;

int main(){
    int N,C,F,total;
    int low[100005],high[100005];
    P cows[100005];
    scanf(" %d %d %d",&N,&C,&F);
    for(int i=0;i<C;++i){
        scanf(" %d %d",&cows[i].sc,&cows[i].f);
    }
    sort(cows,cows+C);
    {
        total=0;
        priority_queue<int,vector<int>,less<int> > pq;
        for(int i=0;i<C;++i){
            low[i]=(pq.size()==N/2?total:INF);
            pq.push(cows[i].f);
            total+=cows[i].f;
            if(pq.size()>N/2){
                total-=pq.top();
                pq.pop();
            }
        }
    }
    {
        total=0;
        priority_queue<int,vector<int>,less<int> > pq;
        for(int i=C-1;i>=0;--i){
            high[i]=(pq.size()==N/2?total:INF);
            pq.push(cows[i].f);
            total+=cows[i].f;
            if(pq.size()>N/2){
                total-=pq.top();
                pq.pop();
            }
        }
    }
    int ans=-1;
    for(int i=C-1;i>=0;--i)
        if(low[i]+high[i]+cows[i].f<=F){
            ans=cows[i].sc;
            break;
        }
    printf("%d\n",ans);
    return 0;
}
