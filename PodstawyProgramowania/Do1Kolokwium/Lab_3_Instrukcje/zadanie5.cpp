#include <iostream>

using namespace std;
int main()
{
	float sum = 0;
	float x;

	while(true)
	{
		cin >> x;
		sum += x;
		if(x==0) break;
	}

	cout << sum << endl;
	return 0;


}
