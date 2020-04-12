#include<cstdio>

int main()
{
	int s[4],g[4];
	int N,A,B;
	bool finds[4],findg[4];
	while(scanf(" %d %d %d %d",&s[0],&s[1],&s[2],&s[3])!=EOF){
		scanf(" %d",&N);
		for(int t=0;t<N;++t){
			A=0;
			B=0;
			for(int i=0;i<4;++i){
				scanf(" %d",&g[i]);
				if(g[i]==s[i]){
					finds[i]=true;
					findg[i]=true;
					++A;
				}
				else{
					finds[i]=false;
					findg[i]=false;
				}
			}
			for(int i=0;i<4;++i)
				if(findg[i]==false)
					for(int j=0;j<4;++j)
						if(g[i]==s[j]&&finds[j]==false){
							++B;
							finds[j]=true;
							findg[i]=true;
							break;
						}
			printf("%dA%dB\n",A,B);
		}
	}
	return 0;
}