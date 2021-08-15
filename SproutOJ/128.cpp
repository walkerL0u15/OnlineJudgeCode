//sprout oj
#include<cstdio>

int arr[1026][1026]={0};
void dc(int len){
    for(int i=0;i<len>>1;++i)
        for(int j=0;j<len>>1;++j){
            arr[i+(len>>1)][j+(len>>1)]=arr[i][j];
            arr[i][j+(len>>1)]=arr[i][j]+len;
            arr[i+(len>>1)][j]=arr[i][j]+len;
            if(arr[i][j]==2) arr[i+(len>>1)][j]-=2;
        }
    return;
}

void solve(int N){
    arr[0][0]=2,arr[1][1]=2,arr[0][1]=3,arr[1][0]=1;
    if(N==1){
        Report(1);return;
    }
    int n=4;
    while(n<=N){
        dc(n);
        n<<=1;
    }
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            Report(arr[i][j]);
    return;
}
