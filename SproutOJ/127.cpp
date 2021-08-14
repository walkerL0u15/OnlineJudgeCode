#include<cstdio>
#include<cstring>

int arr[(int)1e6+10];

void binary_search(int L,int R,int sL,int sR){
    int mid=(L+R)/2;
    if(arr[mid]!=-1) return;
    int big=-1,best,g;
    for(int i=sL;i<sR;++i){
        g=GetVal(mid,i);
        if(g>big){
            big=g,best=i;
        }
    }
    arr[mid]=best;
    binary_search(L,mid,sL,best);
    binary_search(mid,R,best+1,sR);
    return;
}

void solve(int N,int M){
    memset(arr,-1,sizeof(arr));
    binary_search(1,N+1,1,M+1);
    for(int i=1;i<=N;++i)
        Report(arr[i]);
    return;
}
