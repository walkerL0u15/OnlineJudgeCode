#include<cstdio>

int main(){
	int a1,a2,a3,b1,b2,b3,p,c;
	scanf(" %d %d %d %d %d %d %d",&a1,&a2,&a3,&b1,&b2,&b3,&p);
	int ans=a1*p*p+a2*p+a3+b3;
	for(int i=0,j=p;i<=p;++i,--j){
		c=a1*i*i+a2*i+a3+b1*j*j+b2*j+b3;
		if(c>ans)
			ans=c;
	}
	printf("%d\n",ans);
	return 0;
}
