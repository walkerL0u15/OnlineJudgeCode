#include<iostream>
#include<algorithm>
using namespace std;

int N;
long long num[11],o[11];
bool used[11];
void way(int u){
    if(u>=N){
        for(int i=0;i<N;++i)
            printf("%lld ",o[i]);
        putchar('\n');
        return;
    }
    for(int i=0;i<N;++i)
        if(used[i]==false){
            o[u]=num[i];
            used[i]=true;
            way(u+1);
            used[i]=false;
    }
    return;
}

int main()
{
    scanf(" %u",&N);
    for(int i=0;i<N;++i){
        scanf(" %lld",&num[i]);
        used[i]=false;
    }
    sort(num,num+N);
    way(0);
    return 0;
}