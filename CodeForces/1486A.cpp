#include<cstdio>
typedef long long ll;

int main(){
    int T;
    ll N,total,t;
    bool can;
    scanf(" %d",&T);
    while(T--){
        scanf(" %lld",&N);
        total=0,can=true;
        for(ll i=0;i<N;++i){
            scanf(" %lld",&t);
            total+=t;
            if(total<i*(i+1)/2){
                can=false;
                for(i+=1;i<N;++i)
                    scanf(" %lld",&t);
                break;
            }
        }
        if(can)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
