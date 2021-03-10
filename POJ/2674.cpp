#include<cstdio>
#include<algorithm>
using namespace std;

int N;
double L,V;
struct A{
    double x;
    bool face;
    char name[255];
}a[32005];
bool cmp(A x,A y){
    return x.x<y.x;
}

int main(){
    while(scanf(" %d",&N)&&N!=0){
        scanf(" %lf %lf",&L,&V);
        char c;
        for(int i=0;i<N;++i) {
            scanf(" %c %lf %s", &c, &a[i].x, a[i].name);
            if(c=='P'||c=='p')
                a[i].face=true;
            else
                a[i].face=false;
        }
        sort(a,a+N,cmp);
        double val=-1;
        int pos;
        bool dir;
        for(int i=0;i<N;++i)
            if(a[i].face){
                val=L-a[i].x,pos=i,dir=true;
                break;
            }
        for(int i=N-1;i>=0;--i)
            if(!a[i].face){
                if(a[i].x>val) val=a[i].x,pos=i,dir=false;
                break;
            }
        int ans=pos;
        if(dir){
            for(int i=pos+1;i<N;++i)
                if(!a[i].face){
                    ++ans;
                }
        }
        else{
            for(int i=pos-1;i>=0;--i)
                if(a[i].face){
                    --ans;
                }
        }
        val/=V;
        printf("%13.2lf %s\n",(int)(val*100.0)/100.0,a[ans].name);
    }
    return 0;
}
