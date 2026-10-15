#include <iostream>
using namespace std;
int main()
{
	int n_minus_2 = 1;
	int n_minus_1 = 1;
	int n_current;
	int n;
	cin >> n;
	if(n==1 || n==2) {
		cout << 1 <<endl;
		return 0;
 	}
	for(int i=3 ; i<=n ; i++) {
		n_current = n_minus_1 + n_minus_2;
		n_minus_2 = n_minus_1;
		n_minus_1 = n_current;
	}
	cout << n_current << endl;
	return 0;
}
