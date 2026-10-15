#include <iostream>
using namespace std;
int main()
{
	int x;
	cin >> x;

	int counter = 0;

	if(x==0) {
		cout << 1 << endl;
		return 0;
	} 

	while(x != 0) {
		x = x/10;
		counter++;
	}
	
	cout << counter << endl;
	return 0;
}

