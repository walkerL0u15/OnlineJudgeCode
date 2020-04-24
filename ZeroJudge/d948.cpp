#include<cstdio>

int main()
{
    int N;
    float gen,A,H,W,bmi;
    scanf(" %d",&N);
    while(N--){
        scanf(" %d %f %f %f",&gen,&A,&H,&W);
        if(gen)
            bmi=13.7*W+5.0*H-6.8*A+66.0;
        else
            bmi=9.6*W+1.8*H-4.7*A+655.0;
        printf("%.2f\n",bmi);
    }
    return 0;
}