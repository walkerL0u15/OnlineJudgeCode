#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=-6*(1e8);

struct S{
    int val,a,b;
}s[1005*1005];
struct cmp2{
    bool operator()(S x,int y) const{
        return x.val<y;
    }
};
bool cmp(S x,S y){
    return x.val<y.val;
}
int num[1005];

int main(){
    int N;
    while(scanf(" %d",&N)==1&&N!=0){
        for(int i=0;i<N;++i)
            scanf(" %d",&num[i]);
        sort(num,num+N);
        int cnt=0;
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j) {
                s[cnt].val = num[i] + num[j];
                s[cnt].a=i,s[cnt].b=j;++cnt;
            }
        int ans=INF;
        sort(s,s+cnt,cmp);
        for(int d=N-1;d>=0;--d) {
            for (int c = N - 1; c >= 0; --c) {
                if(c==d) continue;
                int cd = num[d] - num[c];
                int p = lower_bound(s, s + cnt,cd, cmp2()) - s;
                for (int i = p; i<cnt&&s[i].val == cd; ++i)
                    if (s[i].a != c && s[i].b != c && s[i].a != d && s[i].b != d) {
                        ans = num[d];
                        break;
                    }
                if (ans!=INF) break;
            }
            if(ans!=INF) break;
        }
        if(ans==INF)
            printf("no solution\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
