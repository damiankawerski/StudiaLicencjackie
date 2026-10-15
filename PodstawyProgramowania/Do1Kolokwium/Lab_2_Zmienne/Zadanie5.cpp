#include <iostream>
using namespace std;

int main()
{
	double interval1_start, interval1_end, interval2_start, interval2_end;
	cin >> interval1_start >> interval1_end >> interval2_start >> interval2_end;
	
	if(interval1_end > interval2_start || interval1_start < interval2_end)
	{
		cout << "no intersection\n";
	} 
	else cout << "intesection\n";
	return 0;



}
