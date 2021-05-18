//uva 571
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;


bool arr[1005][1005];
int A_max,B_max,N;
bool Find;
vector<int> path;
void print(int dir){
    switch(dir){
        case 1:
            printf("fill A"); break;
        case 2:
            printf("fill B"); break;
        case 3:
            printf("pour A B"); break;
        case 4:
            printf("pour B A"); break;
        case 5:
            printf("empty A"); break;
        case 6:
            printf("empty B"); break;
    }
    printf("\n");
    return;
}
void dfs(int A,int B){
    if(Find||arr[A][B]) return;
    arr[A][B]=true;
    if(A==N||B==N){Find=true; return;}
    for(int i=1;i<=6;++i){
        path.push_back(i);
        switch(i){
            case 1:
                dfs(A_max,B);
                break;
            case 2:
                dfs(A,B_max);
                break;
            case 3:
                if(A+B>B_max)
                    dfs(A-(B_max-B),B_max);
                else
                    dfs(0,A+B);
                break;
            case 4:
                if(A+B>A_max)
                    dfs(A_max,B-(A_max-A));
                else
                    dfs(A+B,0);
                break;
            case 5:
                dfs(0,B);
                break;
            case 6:
                dfs(A,0);
                break;
        }
        if(Find) break;
        else path.pop_back();
    }
    return;
}

int main(){
    #ifndef ONLINE_JUDGE

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

#endif
    while(scanf(" %d %d %d",&A_max,&B_max,&N)==3){
        memset(arr,0,sizeof(arr));
        Find=false;
        dfs(0,0);
        for(int i=0;i<path.size();++i){
            print(path[i]);
        }
        path.clear();
        printf("success\n");
    }
    return 0;
}
