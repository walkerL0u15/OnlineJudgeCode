#include<stdio.h>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define P pair<int,int>

struct C{int num,l,r;};
bool cmp(C &a,C &b){return a.l<b.l;}

int main()
{
    int N;
    C cows[50003];
    scanf(" %d",&N);
    for(int i=1;i<=N;++i){
        scanf(" %d %d",&cows[i].l,&cows[i].r);
        cows[i].num=i;
    }
    sort(cows+1,cows+1+N,cmp);
    int cnt=0;
    map<int,int> ans;
    priority_queue<P,vector<P>,greater<P>> que;
    for(int i=1;i<=N;++i){
        if((!que.empty())&&cows[i].l>que.top().first){
            ans[cows[i].num]=que.top().second;
            que.pop();
            que.push(P(cows[i].r,ans[cows[i].num]));
        }
        else{
            ++cnt;
            ans[cows[i].num]=cnt;
            que.push(P(cows[i].r,cnt));
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=N;++i)
        printf("%d\n",ans[i]);
    return 0;
}
