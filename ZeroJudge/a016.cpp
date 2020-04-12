#include<sstream>
#include<iostream>

stringstream change;
string s1,s2;
int num,have;

int cal(int total,bool remain,bool add)
{
	while(cin>>s1>>s2){
		if(s2=="("){
			cin>>num;
			change<<cal(num,true);
			change>>s2;
		}
		if(s1=="+"){
			if(add==true)
		}
	}
}

int main()
{
	remain=false;
	ios::sync_with_stdio(false);
	cin>>num;
	cout<<cal(num);
	return 0;
}