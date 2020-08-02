#include<cstdio>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    string num(8,'\0');
    string now,next;
    map<string,int> m;
    int d[]={4,-4,1,-1};
    queue<string> que;
        que.push("01234567");m["01234567"]=0;
        while(!que.empty()){
            now=que.front();que.pop();
            int p;
            for(int i=0;i<8;++i)
                if(now[i]=='0')
                    p=i;
            for(int i=0;i<4;++i){
                int n=p+d[i];
                if(n>=0&&n<8&&!(p==3&&n==4)&&!(p==4&&n==3)){
                    next=now;
                    swap(next[p],next[n]);
                    if(m.find(next)==m.end()){
                        que.push(next);
                        m[next]=m[now]+1;
                    }
                }
            }
        }
    while((num[0]=getchar())!=EOF){
        getchar();
        for(int i=1;i<8;++i){
            num[i]=getchar();
            getchar();
        }
        printf("%d\n",m[num]);
    }
    return 0;
}
