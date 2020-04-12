#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

struct str{int num,P,A;};
bool cmp(str a,str b){
	if(a.P!=b.P)
		return a.P<b.P;
	return a.A<b.A;
}

int main()
{
	//init
	str S[1005];
	map<string,int> Pin,Ain;
	string aname[1005],pname[1005];
	int N,asize=-1,psize=-1;
	char animal[25],place[25];
	//cal
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%s%d%s",&animal,&S[i].num,&place);
		if(Ain.find(animal)==Ain.end()){
			Ain[animal]=++asize;
			aname[asize]=animal;
		}
		if(Pin.find(place)==Pin.end()){
			Pin[place]=++psize;
			pname[psize]=place;
		}
		S[i].P=Pin[place];
		S[i].A=Ain[animal];
	}
	sort(S,S+N,cmp);
	//output
	int i=0,p=0,t,c;
	while(p<=psize){
		printf("%s :",pname[p++].c_str());
		do{
			printf(" %s ",aname[S[i].A].c_str());
			c=0;
			t=i;
			while(i<N&&S[t].P==S[i].P&&S[t].A==S[i].A){
				c+=S[i].num;
				++i;
			}
			printf("%d",c);
			if(i==N||S[i].P!=S[i-1].P)
				printf("\n");
			else
				printf(",");
		}while(i<N&&S[i].P<p);
	}
	return 0;
}