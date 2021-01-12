#include<cstdio>
#include<cmath>

double ballp[105]={0};
double N,H,R,T,FT;

int main(){
    int C;
    scanf(" %d",&C);
    while(C--){
        scanf(" %lf %lf %lf %lf",&N,&H,&R,&T);
        R/=100;
        FT=sqrt(2*H/10);
        for(int i=0;i<N;++i){
            ballp[i]=calc((T-i);
        }
    }
    return 0;
}
