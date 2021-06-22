#include<cstdio>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
#define f first
#define s second
typedef pair<int,char> P;

P letter[30];
bool cmp(P a,P b){
	if(a.f==b.f)
		return a.s<b.s;
	return a.f>b.f;
}

int main(){
	for(int i=0;i<26;++i){
		letter[i].s='A'+i;
		letter[i].f=0;
	}
	char s[105];
	scanf(" %s",s);
	for(int i=0;i<strlen(s);++i)
		letter[s[i]-'A'].f++;
	sort(letter,letter+26,cmp);
	for(int i=0;i<26;++i){
		if(letter[i].f==0)
			break;
		printf("%c",letter[i].s);
	}
	printf("\n");;
	return 0;
}
