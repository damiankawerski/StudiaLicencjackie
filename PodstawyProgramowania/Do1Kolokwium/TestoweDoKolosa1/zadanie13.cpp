#include <iostream>
using namespace std;

bool ifBit1(int n, int index) {
    return (n & (1 << index) != 0);
}

int mostBits(int arr[], int n) {
    int result = arr[0];
    int numberOfBits = 0;

    for(int i = 0 ; i < n ; i++) {
        int counter = 0;
        for(int j = 0 ; j < 32 ; j++) {
            if(ifBit1(arr[i], j)) {
                counter++;
            }
        }
        if(counter >= numberOfBits) {
            numberOfBits = counter;
            result = arr[i];
        }
    }
    return result;
}

int main() {
    int n = 6;
    int arr[n] = {1, 2 ,3 ,4, 5, 64};
    int result = mostBits(arr, n);
    cout << result << endl;
    return 0;
}

// Lepiej:
// #include <iostream>
// using namespace std;


// int mostBits(int arr[],int n) {
//     int result = arr[0];
//     int numberOfBits = 0;
//     for(int i = 0 ; i < n ; i++) {
//         int number = arr[i];
//         int counter = 0;
//         while(number > 0) {
//             counter += number % 2;
//             number /= 2;
//         }
//         if(counter >= numberOfBits) {
//             numberOfBits = counter;
//             result = arr[i];
//         }

//     }
//     return result;
// }

// int main() {
//     int n = 6;
//     int arr[n] = {1, 2, 3, 4, 5, 64};
//     int number = mostBits(arr, n);
//     cout << number << endl;
//     return 0;
// }