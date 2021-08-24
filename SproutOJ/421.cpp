#include<cstdio>
#include<algorithm>
using namespace std;

int T,N,M;
int a,len,dp[(int)1e5+10];
void push(int num){
    int p1=0,p2=0;
    if(num>=M)
        p1=upper_bound(dp+1,dp+1+len,num)-dp;
    if(num*2>=M)
        p2=upper_bound(dp+1,dp+1+len,num*2)-dp;
    if(p1==len+1||p2==len+1)
        ++len;
    dp[p2]=num*2,dp[p1]=num;
    return;
}

int main(){
    scanf(" %d",&T);
    while(T--){
        len=0;
        scanf(" %d %d",&N,&M);
        for(int i=0;i<N;++i){
            scanf(" %d",&a);
            push(a);
        }
        printf("%d\n",len);
    }
}
