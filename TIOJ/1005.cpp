#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int num[51];
bool prime(int a,int b){
	int temp=1;
	while(temp!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a==1;
}

int main()
{
	int N;
	double ans,total;
	while(scanf(" %d",&N)==1&&N!=0){
		ans=0;
		total=0;
		for(int i=0;i<N;++i)
			scanf(" %d",&num[i]);
		sort(num,num+N);
		for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j)
				if(prime(num[j],num[i]))
					ans+=1;
		total=double(N*(N-1)/2);
		if(ans==0)
			puts("No estimate for this data set.");
		else
			printf("%0.6lf\n",sqrt(total*6/ans));
	}
	return 0;
}
