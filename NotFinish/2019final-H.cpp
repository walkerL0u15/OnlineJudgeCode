#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

struct T{
	int x,y,val;
	int g=false;
}
bool cmpy(T a,T b){
	return a.y<b.y;
}
bool cmpx(T a,T b){
	return a.x<b.x;
}
ll pval[5005][5005]={0},pg[5005][5005]={0};

int main(){
	int G,S,W;
	T tr[5005];
	scanf(" %d %d %d",&G,&S,&W);
	for(int i=0;i<G;++i){
		scanf(" %d %d %d",&tr[i].x,tr[i].y,tr[i].val);
		tr[i].g=true;
	}
	for(int i=G;i<G+S;++i)
		scanf(" %d %d %d",&tr[i].x,&tr[i].y,&tr[i].val);
	sort(tr,tr+G+S,cmpx);
	int now=tr[0].x,cntx=1,cnty=1;
	for(i=0;i<G+S;++i){
		if(tr[i].x==now)
			tr[i].x=cntx;
		else{
			now=tr[i].x;
			tr[i].x=++cntx;
		}
	}
	sort(tr,tr+G+S,cmpy);
	now=tr[0].y;
	for(int i=0;i<G+S;++i){
		if(tr[i].y==now)
			tr[i].y=cnty;
		else{
			now=tr[i].y;
			tr[i].y=++cnty;
		}
		pval[tr[i].x][tr[i].y]=tr[i].val;
		pg[tr[i].x][tr[i].y]=tr[i].g;
	}
	for(int i=0;i<G+S;++i)
		for(int j=0;j<G+S;++j){
			pval[i][j]+=pval[i-1][j]+pval[i][j-1]-pval[i-1][j-1];
			pg[i][j]+=pg[i-1][j]+pg[i][j-1]-pg[i-1][j-1];
		}
	ll ans=-1,total;
	for(int i=0;i<G+S;++i)
		for(int j=i+1;j<G+S;++j)
			if(pg[i][j])
}
