#include<stdio.h>

int main(){
	unsigned long long h,m,s;
	scanf(" %llu %llu %llu",&h,&m,&s);
	m+=s/60,s%=60;
	h+=m/60,m%=60;
	h%=24;
	if(h<10) putchar('0');
	printf("%llu:",h);
	if(m<10) putchar('0');
	printf("%llu:",m);
	if(s<10) putchar('0');
	printf("%llu\n",s);
	return 0;
}
