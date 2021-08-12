#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int &x,int &y){
    return x>y;
}

int main(){
    int n,a[105],total=0,sum=0;
    scanf(" %d",&n);
    for(int i=0;i<n;++i){
        scanf(" %d",&a[i]);
        total+=a[i];
    }
    sort(a,a+n,cmp);
    total/=2;
    int i=0;
    for(;sum<=total;++i)
        sum+=a[i];
    printf("%d\n",i);
}
