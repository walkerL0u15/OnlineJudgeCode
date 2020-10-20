#include<cstdio>
#include<cstring>

int cx[]={1,-1,0,0};
int cy[]={0,0,1,-1};

int main(){
	int R,C,per,day,city[55][55],add[55][55],m=-1,s=1e9;
	scanf(" %d %d %d %d",&R,&C,&per,&day);
	memset(city,-1,sizeof(city));
	memset(add,0,sizeof(add));
	for(int i=1;i<=R;++i)
		for(int j=1;j<=C;++j)
			scanf(" %d",&city[i][j]);
	for(int i=0;i<day;++i){
		for(int j=1;j<=R;++j)
			for(int k=1;k<=C;++k)
				for(int l=0;l<4;++l)
					if(city[j+cx[l]][k+cy[l]]!=-1){
						add[j+cx[l]][k+cy[l]]+=city[j][k]/per;
						add[j][k]-=city[j][k]/per;
					}
		for(int j=1;j<=R;++j)
			for(int k=1;k<=C;++k)
				city[j][k]+=add[j][k];
		memset(add,0,sizeof(add));
	}
	for(int i=1;i<=R;++i)
		for(int j=1;j<=C;++j)
			if(city[i][j]!=-1){
				if(city[i][j]>m)
					m=city[i][j];
				if(city[i][j]<s)
					s=city[i][j];
			}
	printf("%d\n%d\n",s,m);
	return 0;
}
