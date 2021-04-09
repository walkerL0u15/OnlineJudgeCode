#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MaxN=1e5;

int N,M,s,e,k,box_s;
vector<int> box[(int)sqrt(MaxN)+10];
int a[MaxN+5],sa[MaxN+5];
void init(){
    for(int i=0;i<box_s;++i){
        for(int j=0;j<box_s;++j)
            box[i].push_back(i*box_s+j);
        sort(box[i].begin(),box[i].end());
    }
    return;
}
int T(int num){//as[num]
    int sb=(s+box_s-1)/box_s;
    int eb=e/box_s;
}
int BS(){
    int l=-1,r=N+1;
    while(r-l>1){
        int mid=(r+l)/2;
        if(T(mid)>=k)
            r=mid;
        else
            l=mid;
    }
    return r;
}

int main(){
    scanf(" %d %d",&N,&M);
    for(int i=0;i<N;++i)
        scanf(" %d",&a[i]);
    memcpy(sa,a,sizeof(a));
    sort(sa,sa+N);
    box_s=sqrt(N);
    init();
    while(M--){
        scanf(" %d %d %d",&s,&e,&k);
        printf("%d\n",a[BS()]);
    }
    return 0;
}
