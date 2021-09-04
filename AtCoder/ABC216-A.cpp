//ABC216-A
#include<cstdio>

int main(){
	int X,Y;
	char a;
	scanf(" %d %c %d",&X,&a,&Y);
	printf("%d",X);
	if(Y<=2)
		printf("-");
	else if(Y>=7)
		printf("+");
	printf("\n");
	return 0;
}
