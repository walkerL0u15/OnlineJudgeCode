#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;

int main()
{
	int b,N;
    long long t=0;
    scanf(" %d %d",&b,&N);
    string Ns=to_string(N);
    int Nsize=Ns.size();
    for(int i=0;i<Nsize;++i)
        t+=pow(Ns[i]-'0',Nsize)+0.3;
    for(int i=Nsize-1,j=1;i>=0;--i,j*=b)
        t-=(Ns[i]-'0')*j;
    if(t==0)
        puts("YES");
    else
        puts("NO");
    return 0;
}
