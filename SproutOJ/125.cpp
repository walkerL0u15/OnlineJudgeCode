//sprout oj
#include<cstdio>
using namespace std;
typedef long long ll;
const ll Mod=10000019;

int N,arr[(int)1e6+10],arrc[(int)1e6+10];
ll ans=0;
void dc(int L,int R){
    if(R-L<=1) return;
    dc(L,(L+R+1)/2);dc((L+R+1)/2,R);
    ll add=0;
    for(int l=L,r=(L+R+1)/2;l<(L+R+1)/2;++l){
        while(r<R&&arr[l]>arr[r]){
            add=(add+arr[r])%Mod;
            ++r;
        }
        ans=(ans+(ll)arr[l]*(ll)(r-(L+R+1)/2)+add)%Mod;
    }
    int l=L,r=(L+R+1)/2;
    for(int i=L;i<R;++i){
        if(l==(L+R+1)/2)
            arrc[i]=arr[r++];
        else if(r==R)
            arrc[i]=arr[l++];
        else if(arr[l]<arr[r])
            arrc[i]=arr[l++];
        else
            arrc[i]=arr[r++];
    }
    for(int i=L;i<R;++i)
        arr[i]=arrc[i];
    return;
}


int main(){
    scanf(" %d",&N);
    for(int i=0;i<N;++i)
        scanf(" %d",&arr[i]);
    dc(0,N);
    printf("%lld\n",ans);
    return 0;
}
