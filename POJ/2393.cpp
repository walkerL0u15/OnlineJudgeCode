#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int N,S,yogurt,give,minc=2000000;
    long long ans=0;
    scanf(" %d %d",&N,&S);
    for(int i=0;i<N;++i){
        scanf(" %d %d",&yogurt,&give);
        minc=min(yogurt,minc+S);
        ans+=minc*give;
    }
    printf("%lld\n",ans);
    return 0;
}
