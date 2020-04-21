#include<cstdio>
#include<string.h>
using namespace std;

bool used[22],can;
int num[22],N,need;
bool rect(int t,int re){
	if(t==need)
		return true;
	if(used[re]==true){
		used[re]=false;
		if(rect(t+num[re],re+1))
			return true;
	}
	if(rect(t,re+1))
		return true;
	return false;
}

int main()
{
	int T;
	scanf(" %d",&T);
	while(T--){
		can=true;
		need=0;
		memset(used,0,sizeof(used));
		scanf(" %d",&N);
		for(int i=0;i<N;++i){
			scanf(" %d",&num[i]);
			need+=num[i];
		}
		if(need%4!=0){
			puts("no\n");
			continue;
		}
		need/=4;
		for(int i=0;i<4;++i){
			can=rect(0,0);
			if(!can)
				break;
		}
		if(can==true)
			puts("yes\n");
		else
			puts("no\n");
	}
}
