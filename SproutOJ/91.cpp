//sprout 91
#include<cstdio>
#include<cstring>
typedef long long ll;

int main(){
    int T;
    int num[15];
    ll N;
    scanf(" %d",&T);
    while(T--){
        memset(num,0,sizeof(num));
        scanf(" %lld",&N);
        for(int i=9;i>1;--i)
            while(N%i==0){
                N/=i;++num[i];
            }
        if(N!=1)
            printf("-1\n");
        else{
            bool one=true;
            for(int i=2;i<=9;++i){
                while(num[i]>0){
                    printf("%d",i);
                    --num[i],one=false;
                }
            }
            if(one) printf("1");
            printf("\n");
        }
    }
    return 0;
}
