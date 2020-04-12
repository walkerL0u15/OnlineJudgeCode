#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N,R,x[1005],ans,i,j;
    while(scanf("%d%d",&R,&N)&&R!=-1&&N!=-1){
        ans=0;
        for(i=0;i<N;++i)
            scanf(" %d",&x[i]);
        i=0;
        sort(x,x+N);
        while(i<N){
            int s=x[i++];
            while(i<N&&x[i]<=s+R) ++i;
            s=x[i-1];
            while(i<N&&x[i]<=s+R) ++i;
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}