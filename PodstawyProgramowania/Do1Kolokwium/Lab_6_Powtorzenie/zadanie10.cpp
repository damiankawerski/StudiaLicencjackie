#include <iostream>
using namespace std;
int main() 
{
	int x, y;
    cin >> x >> y;
	if(x<2) return 0;

	for(int i=x ; i<=y ;i++) {
		bool is_first_number = true;
		for(int j=2 ; j<i;  j++) {
			if(i%j==0) {
				is_first_number = false;
				break; 
			}
		}
        
		if(is_first_number) cout << i << " ";
	}
	return 0;
}
