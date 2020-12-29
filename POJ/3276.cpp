#include<cstdio>
const int INF=0x3f3f3f3f;

int N;
int dir[5005]={0};
int calc(int K){
    int f[5005]={0};
    int res=0,sum=0;
    for(int i=1;i+K-1<=N;++i){
        if((sum+dir[i])%2!=0){
            ++res;++sum;
            f[i]=1;
        }
        if(i-K+1>=1) sum-=f[i-K+1];
    }
    for(int i=N-K+2;i<=N;++i){
        if((sum+dir[i])%2!=0){
            return INF;
        }
        if(i-K+1>=1) sum-=f[i-K+1];
    }
    return res;
}

int main(){
    int K,M=INF;
    scanf(" %d",&N);
    {
        char c;
        for(int i=1;i<=N;++i){
            scanf(" %c",&c);
            if(c=='B') dir[i]=1;
        }
    }
    for(int k=1;k<=N;++k){
        int m=calc(k);
        if(M>m){
            M=m;
            K=k;
        }
    }
    printf("%d %d\n",K,M);
    return 0;
}
