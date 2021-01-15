#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
double ballp[105]={0};
double H,R,T,FT;
double calc(double t){
    if(t<=0) return H;
    int times=(int)t/FT;
    double d;
    if(times&1)
        d=FT*(times+1)-t;
    else
        d=t-FT*times;
    return H-5*d*d;
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
