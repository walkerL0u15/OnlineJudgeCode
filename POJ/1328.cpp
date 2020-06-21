#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
using namespace std;

struct I{double l,r;};
bool cmp(I &a,I &b){
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}

int main()
{
    int N,cnt,time=1;
    double x,y,d,now;
    I land[1002];
    bool flag;
    while(scanf(" %d %lf",&N,&d)==2&&N!=0){
        flag=false;
        for(int i=0;i<N;++i){
            scanf(" %lf %lf",&x,&y);
            if(y>d) flag=true;
            else{
                land[i].l=x-sqrt(d*d-y*y);
                land[i].r=x+sqrt(d*d-y*y);
            }
        }
        if(flag){
            printf("Case %d: -1\n",time++);
            continue;
        }
        sort(land,land+N,cmp);
        now=land[0].r,cnt=1;
        for(int i=1;i<N;++i)
            if(now<land[i].l)
                now=land[i].r,++cnt;
        printf("Case %d: %d\n",time++,cnt);
    }
    return 0;
}
