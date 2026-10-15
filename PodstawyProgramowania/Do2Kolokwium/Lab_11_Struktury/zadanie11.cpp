#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Task {
    const char* taskName;
    int priority;
    void (*run)(const char*, int);
};

void print(const char* str, int prio) {
    cout << str << endl;
    cout << prio << endl;
}

bool sort_cond(const Task *a, const Task *b) {
    return a->priority < b->priority;
}

int main() {
    int n = 2;
    Task** arr = new Task*[n];
    for(int i = 0 ; i < n ; i++) {
        arr[i] = new Task;
        arr[i]->taskName = "Example Task";
        arr[i]->priority = i + 1;
        arr[i]->run = &print;
    }
    sort(arr, arr + n, sort_cond);
    for(int i = 0 ; i < n ; i++) {
        arr[i]->run(arr[i]->taskName, arr[i]->priority);
    }
    for(int i = 0 ; i < n ; i++) {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}