#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int N,C,week=0,num,m[25];
map<int,int> c;
int use[25];
int solve(){
    int minimum=200000000;
    for(int i=0;i<=N;++i)
        if(use[i]>0)
            minimum=min(minimum,c[m[i]]/use[i]);
    for(int i=0;i<=N;++i)
        c[m[i]]-=(use[i]*minimum);
    return minimum;
}

int main(){
    scanf(" %d %d",&N,&C);
    for(int i=0;i<N;++i){
        scanf(" %d %d",&m[i],&num);
        c[m[i]]=num;
    }
    sort(m,m+N);
    N--;
    while(N>=0&&m[N]>=C)
        week+=c[m[N]],N--;
    int left,a;
    while(true){
        left=C;
        memset(use,0,sizeof(use));
        for(int i=N;i>=0;--i){
            use[i]=min(c[m[i]],left/m[i]);
            left-=use[i]*m[i];
        }
        if(left==0){
            week+=solve();
            continue;
        }
        for(int i=0;i<=N;++i){
            if(c[m[i]]>0&&m[i]>left){
                use[i]++;
                left=-1;
                break;
            }
        }
        if(left<0)
            week+=solve();
        else
            break;
    }
    printf("%d\n",week);
    return 0;
}
