#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	string s;
	bool f;
	while(cin>>s&&s!="."){
		for(int i=1;i<=s.size();++i){
			if(s.size()%i!=0)
				continue;
			f=true;
			for(int j=0;j<s.size();j+=i){
				for(int k=0;k<i;++k)
					if(s[j+k]!=s[k]){
						f=false;
						break;
					}
				if(f==false)
					break;
			}
			if(f==true){
				printf("%d\n",(s.size()/i));
				break;
			}
		}
	}
	return 0;
}