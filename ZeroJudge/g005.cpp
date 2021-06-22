#include<cstdio>
#include<cstring>

int L;
char s[305];
bool way=true;
void print(int f,int e){
	if(way)
		for(int j=f;j<e;++j)
			printf("%c",s[j]);
	else
		for(int j=e-1;j>=f;--j)
			printf("%c",s[j]);
	return;
}

int main(){
	scanf(" %s",s);
	L=strlen(s);
	int l=0;
	for(int i=0;i<L;++i){
		if(s[i]=='+'){
			print(l,i);
			way=true;
			l=i+1;
		}
		else if(s[i]=='-'){
			print(l,i);
			way=false;
			l=i+1;
		}
	}
	print(l,L);
	printf("\n");
	return 0;
}
