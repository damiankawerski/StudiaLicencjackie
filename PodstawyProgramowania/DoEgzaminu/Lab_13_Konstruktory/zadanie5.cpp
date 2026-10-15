#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
    int *array;
    int size;
public:
    Array() : size(0), array(nullptr) {}

    Array(int size, int *arr) {
        this->size = size;
        array = new int[size];
        copy(arr, arr + size, array);
    }

    Array(Array &arr) {
        size = arr.size;
        copy(arr.array, arr.array + size, this->array);
    }

    ~Array() {
        delete[] array;
    }

    int &at(int i) {
        return array[i];
    }

    void resize(int size) {
        int *arr = new int[size];
        this->size = size;
        copy(array, array + this->size, arr);
        delete[] array;
        array = arr;
    }

    void append(int v) {
        resize(size + 1);
        array[size - 1] = v;
    }

    void insert(int i, int v) {
        resize(size + 1);
        for(int j = size - 2; j >= i ; j--) {
            array[j + 1] = array[j];
        }
        array[i] = v;
    }

    int size1() {
        return this->size;
    }

    void clear() {
        delete[] array;
        array = nullptr;
        size = 0;
    }

    void show() {
        for(int i = 0 ; i < size ; i++) {
            cout << array[i] << " ";
        }
    }
};

int main() {
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    int v = 11;
    int i = 1;

    Array t = Array(size, arr);

    cout << t.size1() << endl;
    t.append(v);
    t.insert(i, v);
    t.show();
    cout << endl;
    cout << t.size1() << endl;

    return 0;

}