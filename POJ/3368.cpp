#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MaxN=1e5,MaxNN=1<<17;

int N,Q,s,e,m,mm;
int a[MaxN+10],L[MaxN+10],R[MaxN+10],len[MaxN+10];//[L,R)
int dat[MaxNN*2];
void update(int k,int val){
    k+=mm-1;
    while(k>0){
        k=(k-1)/2;
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
    return;
}

int main(){
    while(scanf(" %d %d",&N,&Q)==2&&N!=0){
        memset(dat,-1,sizeof(dat));
        memset(len,0,sizeof(len));
        for(int i=0;i<N;++i)
            scanf(" %d",&a[i]);
        //cal left and right
        m=0,s=0,e=0;
        while(s<N){
            while(e<N&&a[s]==a[e])
                len[m]++;
            L[m]=s,R[m]=e;
            s=e,m++;
        }
        mm=1;
        while(mm<m) mm<<=1;
        for(int i=0;i<m;++i)
            update(i,len[i]);
        //cal
        while(Q--){
            scanf(" %d %d",&s,&e);
            --s;//[s,e)
            int sb=upper_bound(L,L+m,a[s])-L;//[sb,eb)
            int eb=upper_bound(R,R+m,a[e])-R;
        }
    }
}
