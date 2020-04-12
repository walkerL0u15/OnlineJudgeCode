#include<iostream>
#include<sstream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int total;
	string sen;
	while(getline(cin,sen)){
		total=0;
		stringstream found(sen);
		while(found>>sen)
			total+=stoi(sen);
		cout<<total<<"\n";
	}
	return 0;
}