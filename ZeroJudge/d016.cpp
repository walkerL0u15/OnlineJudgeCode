#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

int a,b;
stack<int> s;
void cal(){
	a=s.top();
	s.pop();
	b=s.top();
	s.pop();
	return;
}
int to_int(string a){
	stringstream b;
	int c;
	b<<a;
	b>>c;
	return c;
}

int main()
{
	string count;
	stringstream form;
	while(getline(cin,count)){
		s=stack<int>();
		form<<count;
		while(form>>count){
			if(count=="+"){
				cal();
				s.push(a+b);
			}
			else if(count=="-"){
				cal();
				s.push(b-a);
			}
			else if(count=="*"){
				cal();
				s.push(a*b);
			}
			else if(count=="/"){
				cal();
				s.push(b/a);
			}
			else if(count=="%"){
				cal();
				s.push(b%a);
			}
			else
				s.push(to_int(count));
		}
		form.clear();
		printf("%d\n",s.top());
	}
	return 0;
}