#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int k,cmd;
    ll N,m;
    while(scanf(" %d %lld",&k,&m)==2){
        set<ll> p[205];
        while(k--){
            scanf(" %d",&cmd);
            if(cmd==1){
                scanf(" %lld",&N);
                p[N%m].insert(N);
            }
            else if(cmd==2){
                scanf(" %lld",&N);
                p[N%m].erase(N);
            }
            else{
                printf("===== s =====\n");
                for(int i=0;i<m;++i){
                    if(i>=100)
                        printf("[%d]:",i);
                    else if(i>=10)
                        printf("[0%d]:",i);
                    else
                        printf("[00%d]:",i);
                    for(set<ll>::iterator it=p[i].begin();it!=p[i].end();++it)
                        printf("%lld -> ",*it);
                    printf("NULL\n");
                }
                printf("===== e =====\n");
            }
        }
    }
    return 0;
}
