#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
double ballp[105]={0};
double H,R,T,FT;
double calc(double t){
    int times=t/FT;
    double lt=t-FT*(double)times;
    if(!times&1)
        lt=FT-lt;
    return H-5*lt*lt;
}

int main(){
    int C;
    scanf(" %d",&C);
    while(C--){
        scanf(" %d %lf %lf %lf",&N,&H,&R,&T);
        R/=100;
        FT=sqrt(2*H/10);
        for(int i=0;i<N;++i){
            ballp[i]=calc(T-i);
        }
        sort(ballp,ballp+N);
        for(int i=0;i<N;++i)
            printf("%.2lf%c",ballp[i]+2*i*R,(i==N-1?'\n':' '));
    }
    return 0;
}
