#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct R{
    double r,l;
}p[1005];
bool cmp(R a,R b){
    return a.r<b.r;
}

int main(){
    int N,cnt,now,Case=1;
    bool can;
    double d,x,y;
    while(scanf(" %d %lf",&N,&d)==2&&N!=0){
        can=true,cnt=1,now=0;
        for(int i=0;i<N;++i){
            scanf(" %lf %lf",&x,&y);
            if(y>d){
                for(i=i+1;i<N;++i)
                    scanf(" %lf %lf",&x,&y);
                printf("Case %d: -1\n",Case++);
                can=false;
                break;
            }
            p[i].r=x+sqrt(d*d-y*y),p[i].l=x-sqrt(d*d-y*y);
        }
        if(!can) continue;
        sort(p,p+N,cmp);
        for(int i=1;i<N;++i)
            if(p[now].r<p[i].l)
                ++cnt,now=i;
        printf("Case %d: %d\n",Case++,cnt);
    }
    return 0;
}
