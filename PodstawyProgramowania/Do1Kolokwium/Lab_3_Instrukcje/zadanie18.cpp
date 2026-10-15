#include <iostream>
using namespace std;
int main() 
{
	int n;
	cin >> n;
	if(n<2) return 0;

	for(int i=2 ; i<=n ;i++) {
		bool is_first_number = true;
		for(int j=2 ; j<i;  j++) {
			if(i%j==0) {
				is_first_number = false;
				break; 
			}
		}
		if(is_first_number) cout << i << endl;
	}
	return 0;
}
