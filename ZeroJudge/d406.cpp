#include<utility>
#include<cstring>
#include<stdio.h>
#include<queue>
using namespace std;
#define P pair<int,int>

int S,r,c,rt,ct;
P t;
int flow[105][105],cht[105][105];
int adr[]={1,0,0,-1};
int adc[]={0,1,-1,0};

int main()
{
    int cas=1;
    while(scanf(" %d",&S)!=EOF){
        memset(flow,0,sizeof(flow));
        memset(cht,0,sizeof(cht));
        scanf(" %d %d",&r,&c);
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                scanf(" %d",&cht[i][j]);
        queue<P > q;
        for(int i=0;i<c;++i)
            if(cht[0][i]){
                q.push({0,i});
                flow[0][i]=1;
                break;
            }
        while(!q.empty()){
            t=q.front();
            q.pop();
            for(int i=0;i<=4-S;++i){
                rt=t.first+adr[i],ct=t.second+adc[i];
                if(rt>=0 && ct>=0 && rt<r && ct<c && flow[rt][ct]==0 && cht[rt][ct]){
                    flow[rt][ct]=flow[t.first][t.second]+1;
                    q.push({rt,ct});
                }
            }
        }
        printf("Case %d:\n",cas);
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j)
                printf("%d ",flow[i][j]);
            printf("\n");
        }
        ++cas;
    }
    return 0;
}
