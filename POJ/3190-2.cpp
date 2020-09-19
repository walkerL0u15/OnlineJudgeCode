#include<cstdio>
#include<algorithm>
using namespace std;

struct C{
    int s,e,num;
}cows[50005];
bool cmp(C a,C b){
    return a.s<b.s;
}

int main(){
    int N,stall=1,use[50005],p[50005];
    bool have;
    use[1]=-1;
    scanf(" %d",&N);
    for(int i=0;i<N;++i){
        scanf(" %d %d",&cows[i].s,&cows[i].e);
        cows[i].num=i;
    }
    sort(cows,cows+N,cmp);
    for(int i=0;i<N;++i){
        have=false;
        for(int j=1;j<=stall;++j)
            if(use[j]<cows[i].s){
                have=true;
                use[j]=cows[i].e,p[cows[i].num]=j;
                break;
            }
        if(!have){
            ++stall;
            use[stall]=cows[i].e;
            p[cows[i].num]=stall;
        }
    }
    printf("%d\n",stall);
    for(int i=0;i<N;++i)
        printf("%d\n",p[i]);
    return 0;
}
