#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MaxN=1e5,B=1000;

int N,M,s,e,k;
int a[MaxN+10],as[MaxN+10];
vector<int> box[MaxN/B+5];
int sum(int x){
    x=as[x];
    int res=0;
    int tr=e+1,tl=s;
    while(tl<tr&&tl%B!=0) if(a[tl++]<=x) ++res;
    while(tl<tr&&tr%B!=0) if(a[--tr]<=x) ++res;
    for(int i=tl/B;i<=tr/B-1;++i)
        res+=upper_bound(box[i].begin(),box[i].end(),x)-box[i].begin();
    return res;
}
int BS(){
    int r=N+1,l=-1;
    while(r-l>1){
        int mid=(r+l)/2;
        if(sum(mid)>=k)
            r=mid;
        else
            l=mid;
    }
    return r;
}

int main(){
    scanf(" %d %d",&N,&M);
    for(int i=0;i<N;++i){
        scanf(" %d",&a[i]);
        box[i/B].push_back(a[i]);
    }
    for(int i=0;i<=(N-1)/B;++i)
        sort(box[i].begin(),box[i].end());
    memcpy(as,a,sizeof(a));
    sort(as,as+N);
    while(M--){
        scanf(" %d %d %d",&s,&e,&k);
        --s,--e;
        printf("%d\n",as[BS()]);
    }
    return 0;
}
