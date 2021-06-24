//sprout
#include<cstdio>
#include<vector>
using namespace std;
const int MaxN=(int)1e5;

struct Node{
    int t=-1;
    vector<int> child;
}box[MaxN+10];
int count(int cur){
    if(box[cur].t!=-1){
        return box[cur].t+1;
    }
    int total=0;
    for(int i=0;i<box[cur].child.size();++i){
        total+=count(box[cur].child[i]);
    }
    box[cur].t=total;
    return total+1;
}

int main(){
    int T,N,M,Q;
    int x,y,q;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d",&N,&M);
        for(int i=0;i<=N;++i){
            box[i].t=-1;box[i].child.clear();
        }
        while(M--){
            scanf(" %d %d",&x,&y);
            box[x].child.push_back(y);
        }
        scanf(" %d",&Q);
        while(Q--){
            scanf(" %d",&q);
            printf("%d\n",count(q));//在%d前多加了一個空格debug了一小時%*^%^%&%*
        }
    }
    return 0;
}
