#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
#define f first
#define s second

P l[100005];
int ans[100005];
bool cmp(int &x,int &y){
    return l[x].f<l[y].f;
}

int main(){
    int T,N,M;
    scanf(" %d",&T);
    while(T--){
        N=0;
        scanf(" %d",&M);
        int a,b;
        while(scanf(" %d %d",&a,&b)&&(a!=0||b!=0))
            l[N++]=make_pair(a,b);
        sort(l,l+N);
        int L=0,i=0,cnt=0,maxR,maxI;;
        while(L<M){
            maxR=L,maxI=-1;
            while(i<N){
                if(l[i].f<=L){
                    if(l[i].s>maxR)
                        maxR=l[i].s,maxI=i;
                }
                else break;
                ++i;
            }
            if(maxI==-1)
                break;
            else
                ans[cnt++]=maxI,L=l[maxI].s;
        }
        if(maxI==-1)
            printf("0\n\n");
        else{
            printf("%d\n",cnt);
            sort(ans,ans+cnt,cmp);
            for(int i=0;i<cnt;++i)
                printf("%d %d\n",l[ans[i]].f,l[ans[i]].s);
        }
    }
}
