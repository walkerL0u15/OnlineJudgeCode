#include<cstdio>
#include<cstring>

int T,N,Q,bit[1005][1005]={0};
void add(int x,int y,int v){
	for(int i=x;i<=N;i+=i&-i)
		for(int j=y;j<=N;j+=j&-j)
			bit[i][j]+=v;
	return;
}
int sum(int x,int y){
	int ans=0;
	for(int i=x;i>0;i-=i&-i)
		for(int j=y;j>0;j-=j&-j)
			ans+=bit[i][j];
	return ans;
}
void rec(){
	int x1,y1,x2,y2;//1:up left 2:down right
	scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
	add(x1,y1,1);add(x2+1,y2+1,1);
	add(x1,y2+1,-1);add(x2+1,y1,-1);
	return;
}
void cal(){
	int x,y;
	scanf(" %d %d",&x,&y);
	printf("%d\n",sum(x,y)&1);
	return;
}

int main(){
	char q;
	scanf(" %d",&T);
	while(T--){
		scanf(" %d %d",&N,&Q);
		memset(bit,0,sizeof(bit));
		while(Q--){
			scanf(" %c",&q);
			if(q=='C')
				rec();
			else
				cal();
		}
		printf("\n");
	}
	return 0;
}
