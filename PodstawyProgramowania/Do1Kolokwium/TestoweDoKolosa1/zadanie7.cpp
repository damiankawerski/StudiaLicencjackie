#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double seq(unsigned int n)
{
    if (n == 0)
    {
        cout << "bylem tu 1 " << endl;
        return 0;
    }
    else if (n == 1)
    {

        cout << "bylem tu 2 " << endl;
        return 1;
    }
    else
    {
        cout << "bylem tu 3 " << endl;
        double test = 0;
        test = seq(n - 1) * sqrt(seq(n - 2));
        return test;
    }

}

int main()
{
    srand(time(0));
    unsigned int n = rand() % 101;
    n = 5;
    cout << "Do funkcji weszlo n= " << n << endl;
    cout << "wynik to= " << seq(n) << endl;
    double result = seq(n);
    cout << "result to: " << result << "!!!" << endl;
    return 0;
}