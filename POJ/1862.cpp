#include<stdio.h>
#include<math.h>
#include<functional>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    double bug[102],ans;
    scanf(" %d",&N);
    for(int i=0;i<N;++i)
        scanf(" %lf",&bug[i]);
    sort(bug,bug+N,greater<int>());
    ans=bug[0];
    for(int i=1;i<N;++i)
        ans=2*sqrt(ans*bug[i]);
    printf("%.3lf\n",ans);
    return 0;
}
