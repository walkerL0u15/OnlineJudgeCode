#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int N;
	string s;
	cin>>s>>N;
	sort(s.begin(),s.end());
	N--;
	while(N--)
		next_permutation(s.begin(),s.end());
	cout<<s<<"\n";
	return 0;
}
