#include<stdio.h>
#include<math.h>
#include<iostream>
#include<queue>
using namespace std;
#define MaxN 205
#define INF 1e9

int main()
{
    int N,x[MaxN],y[MaxN],path[MaxN][MaxN],rock[MaxN],cnt=1;
    bool in[MaxN];
    while(scanf(" %d",&N)&&N!=0){
        queue<int> que;
        fill(rock+1,rock+N,INF);
        fill(in,in+N,0);
        for(int i=0;i<N;++i)
            scanf(" %d %d",&x[i],&y[i]);
        for(int i=0;i<N;++i)
            for(int j=i;j<N;++j){
                path[i][j]=pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
                path[j][i]=path[i][j];
            }
        que.push(0);
        while(!que.empty()){
            int q=que.front();que.pop();
            in[q]=false;
            for(int i=1;i<N;++i){
                int m=max(rock[q],path[q][i]);
                if(rock[i]>m){
                    rock[i]=m;
                    if(!in[i]){
                        que.push(i);
                        in[i]=true;
                    }
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cnt,sqrt((double)rock[1]));
        ++cnt;
    }
    return 0;
}
