#include<cstdio>
using namespace std;

int pN=0,prime[2000];
void find_prime(){
    bool is_prime[10005]={0};
    for(int i=2;i<=10000;++i)
        is_prime[i]=true;
    for(int i=2;i<=10000;++i)
        if(is_prime[i]){
            prime[pN++]=i;
            for(int j=i*2;j<=10000;j+=i)
                is_prime[j]=false;
        }
    return;
}

int main(){
    int num;
    find_prime();
    while(scanf(" %d",&num)==1&&num!=0){
        int res=0;
        int sum=prime[0],r=0,l=-1;
        while(r<pN){
            if(sum==num){
                ++res;
                sum+=prime[++r];
            }
            else if(sum<num)
                sum+=prime[++r];
            else
                sum-=prime[++l];
            if(l==r) sum+=prime[++r];
        }
        printf("%d\n",res);
    }
    return 0;
}
