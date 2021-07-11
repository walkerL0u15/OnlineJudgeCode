#include<cstdio>
typedef long long ll;

int N,p1[100005]={0},p2[100005]={0};
int bit[200005]={0};

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=2*N){
        bit[i]+=x;
        i+=i&-i;
    }
    return;
}

int main(){
    ll ans=0;
    scanf(" %d",&N);
    int num;
    for(int i=1;i<=2*N;++i){
        scanf(" %d",&num);
        if(p1[num]==0)
            p1[num]=i;
        else
            p2[num]=i;
    }
    for(int i=1;i<=N;++i){
        int s1=sum(p1[i]),s2=sum(p2[i]);
        if(s1>s2){
            int a=s1;
            s1=s2,s2=a;
        }
        ans+=s2-s1;
        add(p1[i],1);add(p2[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}
