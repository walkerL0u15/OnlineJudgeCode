#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
#define f first
#define s second

P num[100005];

int main(){
    int N,t,k;
    while(scanf(" %d %d",&N,&k)&&N!=0) {
        num[0] = P(0, 0);
        for (int i = 1; i <= N; ++i) {
            scanf(" %d", &num[i].f);
            num[i].s = i;
            num[i].f += num[i - 1].f;
        }
        sort(num, num + N + 1);
        for (int i = 0; i < k; ++i) {
            int r = 1, l = 0, mdis = 0x3f3f3f3f, ans, ans_r, ans_l;
            scanf(" %d", &t);
            while (r <= N) {
                int sum = num[r].f - num[l].f;
                if (abs(sum - t) < mdis) {
                    mdis = abs(sum - t);
                    ans = sum;
                    ans_r = num[r].s, ans_l = num[l].s;
                    if (ans == t) break;
                }
                if (sum < t) ++r;
                else ++l;
                if (l == r) ++r;
            }
            if (ans_r < ans_l) swap(ans_r, ans_l);
            printf("%d %d %d\n", ans, ans_l + 1, ans_r);
        }
    }
    return 0;
}
