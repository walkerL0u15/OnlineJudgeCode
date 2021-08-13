#include<cstdio>
#include<queue>
using namespace std;

int a,want,ans=0,cnt;
char hit[100][3];
queue<bool> base;

void out(int num){
    base.push(true);
    for(int i=0;i<num;++i){
        if(base.front())
            ++ans;
        base.pop();
    }
    for(int i=0;i<num-1;++i)
        base.push(false);
    return;
}

int main(){
    for(int i=0;i<9;++i){
        scanf(" %d",&a);
        for(int j=0;j<a;++j)
            scanf(" %s",hit[i+9*j]);
    }
    scanf(" %d",&want);
    for(int i=0;i<3;++i)
        base.push(false);
    int ho=0;
    for(int i=0;;++i){
        if(ho==want) break;
        if(hit[i][0]=='S'||hit[i][0]=='F'||hit[i][0]=='G'){
            ++ho;
            if(ho%3==0){
                for(int i=0;i<3;++i){
                    base.pop();base.push(false);
                }
            }

        }
        else if(hit[i][0]=='H')
            out(4);
        else
            out(hit[i][0]-'0');
    }
    printf("%d\n",ans);
    return 0;
}
