#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int N,m;
int num[(int)1e5+10];
bool C(int x){
    ll sum=0;
    for(int i=0;i<N;++i)
        sum+=N-(lower_bound(num+i+1,num+N,num[i]+x)-num) ;
    return sum>=m;
}

int main(){
    while(scanf(" %d",&N)!=EOF) {
        m = N * (N - 1) / 2;
        m = (m + 2) / 2;
        for (int i = 0; i < N; ++i)
            scanf(" %d", &num[i]);
        sort(num, num + N);
        int l = -1, r = num[N - 1] - num[0];
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (C(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}
