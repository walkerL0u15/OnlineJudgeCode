//sprout 89
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
#define ct first
#define et second

P f[10005];
bool cmp(P &a,P &b){
    return a.et>b.et;
}

int main(){
    int N;
    while(scanf(" %d",&N)&&N!=0){
        for(int i=0;i<N;++i)
            scanf(" %d %d",&f[i].ct,&f[i].et);
        sort(f,f+N,cmp);
        int ans=-1,tt=0;
        for(int i=0;i<N;++i){
            tt+=f[i].ct;
            ans=max(ans,tt+f[i].et);
        }
        printf("%d\n",ans);
    }
    return 0;
}
