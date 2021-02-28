//用G++丟
#include<cstdio>
#include<algorithm>
using namespace std;

struct T{
    double val;
    int id;
}y[(int)1e5+10];
int N,K;
int w[(int)1e5+10],v[(int)1e5+10];
bool cmp(T a,T b){
    return a.val>b.val;
}
bool C(double x){
    for(int i=0;i<N;++i) {
        y[i].val =(double)v[i]-(double)w[i] * x;
        y[i].id = i + 1;
    }
    sort(y,y+N,cmp);
    double sum=0;
    for(int i=0;i<K;++i)
        sum+=y[i].val;
    return sum>=0;
}

int main(){
    scanf(" %d %d",&N,&K);
    for(int i=0;i<N;++i)
        scanf(" %d %d",&v[i],&w[i]);
    double low=-10,high=1e7;
    while(high-low>1e-7){
        double mid=(low+high)/2;
        if(C(mid))
            low=mid;
        else
            high=mid;
    }
    for(int i=0;i<K;++i)
        printf(" %d",y[i].id);
    printf("\n");
    return 0;
}
