#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int T,N;
    scanf(" %d",&T);
    for(int l=0;l<T;++l){
        scanf(" %d",&N);
        int num[N];
        for(int i=0;i<4;++i)
            scanf(" %d",&num[i]);
        for(int i=4;i<N;++i)
            num[i]=num[i-4]+num[i-1];
        sort(num,num+N);
        printf("%d\n",num[N/2]);
    }
    return 0;
}