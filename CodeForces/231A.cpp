#include<cstdio>
using namespace std;

int main(){
    int n,sum,a,total=0;
    scanf(" %d",&n);
    while(n--){
        sum=0;
        for(int i=0;i<3;++i){
            scanf(" %d",&a);
            sum+=a;
        }
        if(sum>=2)
            ++total;
    }
    printf(" %d",total);
    return 0;
}
