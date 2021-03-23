#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MaxN=1005;

int N,X,Y;
int b[MaxN][MaxN];
int x1[1005],x2[1005];//1: left down
int y1[1005],y2[1005];//2: right up
int compress(int a1[],int a2[],int L){
    vector<int> v;
    for(int i=0;i<N;++i){
        v.push(a1[i]);
        v.push(a2[i]);
    }
    v.push(0);v.push(L);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<N;++i){
        a1[i]=v.find(a1[i])-v.begin();
        a2[i]=v.find(a2[i])-v.begin();
    }
    return v.size()-1;
}

int main(){
    while(scanf(" %d %d",&X,&Y)&&X!=0){
        memset(b,0,sizeof(b));
        scanf(" %d",&N);
        for(int i=0;i<N;++i)
            scanf(" %d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
        X=compress(x1,x2,X);
        Y=compress(y1,y2,Y);
        for(int i=0;i<N;++i){
            b[x1[i]][y2[i]]--;
            b[x1[i]][y1[i]]++;
            b[x2[i]][y1[i]]--;
            b[x2[i]][y2[i]]++;
        }
        for(int i=1;i<=X;++i)
            for(int j=0;j<=Y;++j)
                b[i][j]+=b[i-1][j];
        for(int j=1;j<=Y;++j)
            for(int i=0;i<=X;++i)
                b[i][j]+=b[i][j-1];
        printf("%d\n",bfs());
    }
    return 0;
}
