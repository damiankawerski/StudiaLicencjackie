#include <iostream>
using namespace std;

int main()
{
	unsigned int n;
	cin >> n;

	int max_x;
	cin >> max_x;


	for(int i=1 ; i<n ; i++)
	{
		int temp;
		cin >> temp;
		if(temp > max_x)
		{
			max_x = temp;
			
		}

	}

	cout << max_x << endl;

	return 0;


}
