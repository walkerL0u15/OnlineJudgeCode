#include <iostream>
using namespace std;

int main()
{
	unsigned int a,b;
	cin >> a >> b;
	unsigned int c = b-a;
	while(a%2 == 0 && b%2 == 0)
	{
		cout << c/2+1;
		break;
	}
	while((a%2 == 0 && b%2 != 0) || (a%2 != 0 && b%2 == 0))
	{
		cout << (c+1)/2;
		break;
	}
	while(a%2 != 0 && b%2 != 0)
	{
		cout << c/2;
		break;
	}
	return 0;
}