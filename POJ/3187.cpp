#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int N,t,num[11],cnt=0,numc[11];
    scanf(" %d %d",&N,&t);
    for(int i=0;i<11;++i)
        num[i]=i+1;
    do{
        for(int i=0;i<N;++i)
            numc[i]=num[i];
        for(int i=N-1;i>=1;--i)
            for(int j=0;j<i;++j)
                numc[j]+=numc[j+1];
        if(numc[0]==t) break;
    }while(next_permutation(num,num+N));
    for(int i=0;i<N;++i)
        printf("%d ",num[i]);
    printf("\n");
    return 0;
}
