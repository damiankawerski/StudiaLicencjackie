#include <iostream>
using namespace std;

int main()
{
	unsigned int n; //z tej liczby będziemy liczyć silnię
	long long silnia = 1; //ta zmienna będzie przechowywać wynik

	cout<<"Podaj n: ";
	cin>>n;

	for(int i=n;i>1;i--)
		silnia*=i; //lub silnia = silnia * i

	cout<<n<<"! = "<<silnia<<endl;

	return 0;
}
