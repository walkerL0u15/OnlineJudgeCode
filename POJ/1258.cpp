#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;

int m[105][105];
int mindis[105];
bool used[105]={0};

int main(){
    int N;
    while(scanf(" %d",&N)==1){
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                scanf(" %d",&m[i][j]);
        int res=0;
        fill(mindis,mindis+105,INF);
        fill(used,used+105,0);
        mindis[0]=0;
        while(true){
            int v=-1;
            for(int i=0;i<N;++i)
                if((!used[i])&&(v==-1||mindis[i]<mindis[v]))
                    v=i;
            if(v==-1) break;
            res+=mindis[v];
            used[v]=true;
            for(int i=0;i<N;++i)
                mindis[i]=min(mindis[i],m[v][i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
