#include<cstdio>
#include<iostream>
#include<set>
#include<string>
using namespace std;

set<string> name;

int main(){
	int N;
	string mem;
	scanf(" %d",&N);
	getchar();
	while(N--){
		getline(cin,mem);
		if(name.find(mem)!=name.end()){
			printf("Yes\n");
			return 0;
		}
		name.insert(mem);
	}
	printf("No\n");
	return 0;
}
