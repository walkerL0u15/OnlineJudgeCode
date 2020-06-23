#include<stdio.h>
#include<stack>
using namespace std;

int main()
{
	int T,ans;
	char c;
	scanf(" %d",&T);
	getchar();
	while(T--){
		ans=0;
		stack<char> st;
		while((c=getchar())!='\n'){
			if(c=='p')
				st.push(c);
			else if(c=='q'&&(!st.empty())){
					st.pop();
					++ans;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
