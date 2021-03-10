#include<cstdio>

int main(){
    int T,N,num,last,ans,big;
    scanf(" %d",&T);
    while(T--){
        ans=1;
        scanf(" %d",&N);
        int i=1;
        scanf(" %d",&last);
        while(i<N){
            big=1;
            while(i<N){
                scanf(" %d",&num);
                ++i;
                if(last==num) ++big;
                else break;
            }
            if(big>ans) ans=big;
            last=num;
        }
        printf("%d\n",ans);
    }
    return 0;
}
