#include<iostream>
using namespace std;

bool find(int year){
	if(year%4!=0)
		return false;
	else if(year%100!=0)
		return true;
	else if(year%400!=0)
		return false;
	else
		return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool y;
	long long int total;
	int year[2],month[2],day[2];
	int time[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(cin>>year[0]>>month[0]>>day[0]>>year[1]>>month[1]>>day[1]){
		total=0;
		y=false;
		if(year[0]>year[1]){
			swap(year[0],year[1]);
			swap(month[0],month[1]);
			swap(day[0],day[1]);
		}
		for(int i=year[0]+1;i<year[1];++i){
			y=true;
			if(find(i))
				total+=366;
			else
				total+=365;
		}
		if(abs(year[1]-year[0])==1)
			y=true;
		for(int i=12;i>month[0];--i)
			total+=time[i];
		total+=(time[month[0]]-day[0])+day[1];
		for(int i=1;i<month[1];++i)
			total+=time[i];
		if(month[0]<=2&&find(year[0])&&year[1]!=year[0])
			++total;
		if(month[1]>2&&find(year[1])&&year[1]!=year[0])
			++total;
		if(!y){
			if(month[1]>month[0])
				total-=365;
			else if(month[1]<month[0])
				total=367-total;
			else{
				if(day[0]<=day[1])
					total-=365;
				else
					total-=363;
			}
		}
		cout<<total<<"\n";
	}
}