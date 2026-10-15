#include <iostream>
using namespace std;
int main()
{
	int x;
	cin >> x;

	if(x < 0)
	{
		for(int i=x; i<=0 ; i++) {
		cout << i << endl; }
	}
	else
	{

		for(int i = 0; i < x; i++)
		{
		cout << i << endl;
		}
	}
	return 0;
}
