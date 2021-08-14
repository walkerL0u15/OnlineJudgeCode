#include<cstdio>
using namespace std;

int N,num[2*(int)1e5+10];
void dc(int len){
    if(len>=N){
        for(int i=0;i<len;++i)
            if(num[i]<=N){
                printf("%d ",num[i]);
            }
        printf("\n");
        return;
    }
    for(int i=0;i<len;++i){
        num[i+len]=num[i]*2;
        num[i]=num[i]*2-1;
    }
    dc(len*2);
    return;
}

int main(){
    scanf(" %d",&N);
    num[0]=3,num[1]=1,num[2]=2;
    dc(3);
    return 0;
}
