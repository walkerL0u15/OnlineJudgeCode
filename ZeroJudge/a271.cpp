#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,carrot[5],weight,poison,eaten,minus;
	string s;
	stringstream stream;
	carrot[0]=0;
	cin>>N;
	for(int i=0;i<N;++i){
		minus=0;
		for(int i=1;i<=4;++i){
			cin>>carrot[i];
		}
		carrot[4]=-carrot[4];
		carrot[3]=-carrot[3];
		cin>>poison>>weight;
		cin.ignore();
		stream.str("");
		stream.clear();
		s="";
		s.clear();
		getline(cin,s);
		stream<<s;
		while(stream>>eaten){
			weight-=minus;
			if(weight<0){
				cout<<"bye~Rabbit\n";
				break;
			}
			weight+=carrot[eaten];
			if(eaten==4)
				minus+=poison;
			if(weight<0){
					cout<<"bye~Rabbit\n";
					break;
				}
		}
		if(weight>=0)
			cout<<weight<<"g\n";
	}
	return 0;
}