#include <iostream>
using namespace std;

class Mutex {
private:
    bool isLocked;
public:
    Mutex() : isLocked(false) {}


    void lock() {
        if(isLocked == false) {
            isLocked = true;
        }
    }

    void release() {
        if(isLocked == true) {
            isLocked = false;
        }
    }

    bool state() {
        return isLocked;
    }    
};

int main() {
    //****************************************** DYNAMICZNA
    Mutex *dynamic = new Mutex[6]; 
    delete[] dynamic;
    //****************************************** AUTOMATYCZNA TABLICA OBIEKTOW DYNAMICZNYCH
    Mutex *autom[6];
    for(int i = 0 ; i < 6 ; i++) {
        autom[i] = new Mutex;
    }
    for(int i = 0 ; i < 6 ; i++) {
        delete autom[i];
    }
    //****************************************** DYNAMICZNA TABLICA DYNAMICZNYCH
    Mutex **dynamo = new Mutex*[6];
    for(int i = 0 ; i < 6 ; i++) {
        dynamo[i] = new Mutex;
    }
    for(int i = 0 ; i < 6 ; i++) {
        delete dynamo[i];
    }
    delete[] dynamo;
    //******************************************* 2D Dynamic

    Mutex **arr2d = new Mutex*[6];
    for(int i = 0 ; i < 6 ; i++) {
        arr2d[i] = new Mutex[6];
    }
    for(int i = 0 ; i < 6 ; i++) {
        delete[] arr2d[i];
    }
    delete[] arr2d;

}