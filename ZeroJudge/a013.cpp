#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<char,int> roman;
	roman['I']=1;
	roman['V']=5;
	roman['X']=10;
	roman['L']=50;
	roman['C']=100;
	roman['D']=500;
	roman['M']=1000;
	string one,two;
	long int first,second,ans;
	cin>>one;
	while(true){
		cin>>two;
		first=0;
		second=0;
		for(int i=0;i<one.length();++i)
			first+=roman[one[i]];
		for(int i=0;i<two.length();++i)
			second+=roman[two[i]];
		for(int i=1;i<one.length();++i)
			if(roman[one[i]]>roman[one[i-1]])
				first-=roman[one[i-1]]*2;
		for(int i=1;i<two.length();++i)
			if(roman[two[i]]>roman[two[i-1]])
				second-=roman[two[i-1]]*2;
		ans=first-second;
		if(ans<0)
			ans=-ans;
		else if(ans==0){
			cout<<"ZERO\n";
			cin>>one;
			if(one=="#")
				return 0;
			continue;
		}
		while(ans>=1000){
			cout<<"M";
			ans-=1000;
		}
		if(ans>=900){
			cout<<"CM";
			ans-=900;
		}
		else if(ans>=500){
			cout<<"D";
			ans-=500;
		}
		else if(ans>=400){
			cout<<"CD";
			ans-=400;
		}
		while(ans>=100){
			cout<<"C";
			ans-=100;
		}
		if(ans>=90){
			cout<<"XC";
			ans-=90;
		}
		else if(ans>=50){
			cout<<"L";
			ans-=50;
		}
		else if(ans>=40){
			cout<<"XL";
			ans-=40;
		}
		while(ans>=10){
			cout<<"X";
			ans-=10;
		}
		if(ans>=9){
			cout<<"IX";
			ans-=9;
		}
		else if(ans>=5){
			cout<<"V";
			ans-=5;
		}
		else if(ans==4){
			cout<<"IV";
			ans-=4;
		}
		while(ans>=1){
			cout<<"I";
			ans-=1;
		}
		cout<<"\n";
		cin>>one;
		if(one=="#")
			break;
	}
	return 0;
}