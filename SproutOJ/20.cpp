//sprout 20
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int in[1000005];
queue<int> line; 
queue<int> team[1005];

int main(){
	int N,K,p,cnt=1;;
	char dir[20];
	while(scanf(" %d",&N)!=EOF){
		memset(in,0,sizeof(in));
		printf("Line #%d\n",cnt++);
		for(int i=1;i<=N;++i){
			scanf(" %d",&K);
			while(K--){
				scanf(" %d",&p);
				in[p]=i;
			}
		}
		while(scanf(" %s",dir)&&dir[0]!='S'){
			if(dir[0]=='E'){
				scanf(" %d",&p);
				if(in[p]==0||team[in[p]].empty())
					line.push(in[p]);
				team[in[p]].push(p);
			}
			else{
				printf("%d\n",team[line.front()].front());
				team[line.front()].pop();
				if(line.front()==0||team[line.front()].empty())
					line.pop();
			}
		}
		line=queue<int>();
		for(int i=0;i<1005;++i) team[i]=queue<int>();
	}
	return 0;
}
