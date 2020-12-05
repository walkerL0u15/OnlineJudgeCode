#include<cstdio>
typedef long long ll;


int main(){
    int N,v[25],p[25]={0};
    ll ans=1;
    scanf(" %d",&N);
    for(int i=1;i<=N;++i){
        scanf(" %d",&v[i]);
        p[i]=i;
    }
    for(int i=1;i<=N;++i){
        ans*=p[v[i]];
        for(int j=v[i];j<=N;++j)
            p[j]-=1;
    }
    printf("%lld\n",ans);
    return 0;
}