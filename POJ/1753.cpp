#include<cstdio>

int flip[20]={51200,58368,29184,12544,35968,20032,10016,4880,2248,1252,626,305,140,78,39,19};
long long num=0,i;
bool dfs(int n,int idx,long long total){
	if(n==i){
		if(total==0||total==(1<<16)-1)
			return 1;
		return 0;
	}
	if(idx>=16) return 0;
	return dfs(n+1,idx+1,total^flip[idx])|dfs(n,idx+1,total);
}

int main(){
	char s[10];
	for(i=0;i<4;++i){
		scanf(" %s",s);
		for(int j=0;j<4;++j)
			if(s[j]=='w') num+=1<<((3-i)*4+3-j);
	}
	for(i=0;i<=16;++i)
		if(dfs(0,0,num)){
			printf("%d\n",i);
			return 0;
		}
	printf("Impossible");
	return 0;
}
