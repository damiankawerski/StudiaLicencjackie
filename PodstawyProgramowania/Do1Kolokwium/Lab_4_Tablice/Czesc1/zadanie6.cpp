#include <iostream> 
using namespace std;
int main() {
    const int N = 5;
    float arr1[N];
    float arr2[N];
    for(int i = 0 ; i < N ; i++) {
        cin >> arr1[i];
    }
    for(int i = 0 ; i < N ; i++) {
        cin >> arr2[i];
    }
    float scalar = 0;
    for(int i = 0 ; i < N ; i++) {
        scalar += arr1[i]*arr2[i];
    }
    cout << scalar << endl;
    return 0;

}