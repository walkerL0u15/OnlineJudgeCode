#include<iostream>
#include<math.h>
using namespace std;

int main(){
	double a,b,c;
	int N;
	scanf(" %d",&N);
	for(int i=0;i<N;++i){
		scanf(" %lf %lf %lf",&a,&b,&c);
		a=b*b-4*a*c;
		if(a<0)
			printf("No\n");
		else if(sqrt(a)==int(sqrt(a)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0; 
}