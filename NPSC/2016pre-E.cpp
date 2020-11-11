#include<cstdio>

char pr[100005];

int main(){
    int N;
    scanf(" %d %s",&N,pr);
    int m=0,cnt=0;
    for(int i=0;i<N;++i){
        if(pr[i]=='s')
            ++cnt;
        else
            --cnt;
        if(cnt<0)
            m=i+1,cnt=0;
    }
    if(m==N)
        printf("-1\n");
    else
        printf("%d\n",m);
    return 0;
}
