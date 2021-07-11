//sprout 74
#include<cstdio>

int main(){
    int T,N,stone,best,cnt;
    bool dir;
    scanf(" %d",&T);
    while(T--){
        dir=true,best=-1,cnt=0;
        scanf(" %d",&N);
        for(int i=0;i<N;++i){
            scanf(" %d",&stone);
            if(dir){
                if(stone<best)
                    ++cnt,dir=false;
                best=stone;
            }
            else{
                if(stone>best)
                    ++cnt,dir=true;
                best=stone;
            }
        }
        if(dir)
            ++cnt;
        printf("%d\n",cnt);
    }
    return 0;
}
