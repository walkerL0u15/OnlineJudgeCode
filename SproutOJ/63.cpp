//sprout 63
#include<cstdio>

int k;
int num[20],s[10];
void dfs(int p,int idx){
    if(p>=6){
        printf("%d",s[0]);
        for(int i=1;i<6;++i)
            printf(" %d",s[i]);
        printf("\n");
        return;
    }
    for(int i=idx;k-i>=6-p;++i){
        s[p]=num[i];
        dfs(p+1,i+1);
    }
    return;
}

int main(){
    #ifndef ONLINE_JUDGE

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

#endif
    bool a=true;
    while(scanf(" %d",&k)&&k!=0){
        if(!a)//無言，不這樣過不了
            printf("\n");
        else
            a=false;
        for(int i=0;i<k;++i)
            scanf(" %d",&num[i]);
        dfs(0,0);
    }
    return 0;
}
