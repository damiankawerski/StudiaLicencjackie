#include <iostream>
using namespace std;
int main()
{
	for(int i = 0 ; i<=10 ; i++)
	{
		for(int j = i ; j<=10 ; j++)
		{
			cout << i*j << "\t";
		}
		cout << endl;
	}
	return 0;
}
