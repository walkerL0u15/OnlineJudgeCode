#include<cstdio>

long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    long long a,b;
    while(scanf(" %lld %lld",&a,&b)==2){
        if(b>a){
            int c=a;
            a=b;b=c;
        }
        long long c=gcd(a,b);
        printf("%lld %lld\n",c,a*b/c);
    }
    return 0;
}
