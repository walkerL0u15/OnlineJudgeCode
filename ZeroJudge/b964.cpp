#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int p,st[25];
	while(scanf(" %d",&p)!=EOF){
		for(int i=0;i<p;++i)
			scanf(" %d",&st[i]);
		sort(st,st+p);
		for(int i=0;i<p;++i)
			printf("%d ",st[i]);
		printf("\n");
		int *biter=lower_bound(st,st+p,60),*witer=biter-1;
		if(witer-st<0)
			printf("best case\n");
		else
			printf("%d\n",*witer);
		if(biter-st>p-1)
			printf("worst case\n");
		else
			printf("%d\n",*biter);
	}
	return 0;
}
