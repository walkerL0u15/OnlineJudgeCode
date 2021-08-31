#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

struct A{
	int a=2000,num,p;
	A(int _a=0,int _num=0,int _p=0):a(_a),num(_num),p(_p){}
};
int p_cnt=0,a_cnt=0;
map<string,int> Ptime,Atime;
string Pname[1005];
string Aname[1005];
A animal[1005];

bool cmp(A &x,A &y){
	if(x.p==y.p)
		return x.a<y.a;
	return x.p<y.p;
}

int main(){
	int N,num;
	char a[30],p[30];
	scanf(" %d",&N);
	for(int i=0;i<N;++i){
		scanf(" %s %d %s",&a,&num,&p);
		if(Ptime.find(p)==Ptime.end()){
			Pname[p_cnt]=p;
			Ptime[p]=p_cnt++;
		}
		if(Atime.find(a)==Atime.end()){
			Aname[a_cnt]=a;
			Atime[a]=a_cnt++;
		}
		animal[i]=A(Atime[a],num,Ptime[p]);
	}
	sort(animal,animal+N,cmp);
	int cnt=0;
	for(int i=0;i<p_cnt;++i){
		printf("%s :",Pname[i].c_str());
		while(cnt<N&&animal[cnt].p==i){
			int sum=0,ccnt=cnt;
			while(animal[cnt].p==i&&animal[cnt].a==animal[ccnt].a)
				sum+=animal[cnt++].num;
			printf(" %s %d",Aname[animal[ccnt].a].c_str(),sum);
			if(animal[cnt].p==i) printf(",");
			else printf("\n");
		}
	}
	return 0;
}
