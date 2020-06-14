#include<stdio.h>
#include<iostream>
using namespace std;
#define MaxN 8+2

int main()
{
    int T,N,num[MaxN];
    char m[10];
    long ans;
    scanf(" %d",&T);
    for(int Case=1;Case<=T;++Case){
        ans=0;
        scanf(" %d",&N);
        fill(num,num+N+1,-1);
        for(int i=1;i<=N;++i){
            scanf(" %s",m);
            for(int j=N-1;j>=0;--j)
                if((m[j]-'0')){
                    num[i]=j+1;
                    break;
                }
        }
        for(int i=1;i<=N;++i)
            for(int j=i;j<=N;++j)
                if(num[j]<=i){
                    for(int k=j-1;k>=i;--k)
                        swap(num[k],num[k+1]);
                    ans+=(long)(j-i);
                    break;
                }
        printf("Case #%d: %ld\n",Case,ans);
    }
    return 0;
}
