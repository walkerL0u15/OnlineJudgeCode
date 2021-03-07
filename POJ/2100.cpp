#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define f first
#define s second

vector<P> res_n;

int main(){
    ull N,Max_r=1;
    scanf(" %llu",&N);
    while(Max_r*Max_r<=N) ++Max_r;
    ull r=1,l=0,sum=1;
    while(r<Max_r){
        if(sum==N) {
            res_n.push_back(P(l + 1, r));
            ++r,sum+=r*r;
        }
        else if(sum<N){
            ++r,sum+=r*r;
        }
        else{
            ++l,sum-=l*l;
        }
        if(r==l){
            ++r,sum+=r*r;
        }
    }
    printf("%d\n",res_n.size());
    for(int i=0;i<res_n.size();++i){
        printf("%d",res_n[i].s-res_n[i].f+1);
        for(int j=res_n[i].f;j<=res_n[i].s;++j)
            printf(" %d",j);
        printf("\n");
    }
    return 0;
}
