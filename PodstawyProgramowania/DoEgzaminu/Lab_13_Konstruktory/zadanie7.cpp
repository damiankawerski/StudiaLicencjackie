#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Hotel {
private:
    char* name;
    int rooms;
    int reserved_rooms;
    float grade;
public:
    Hotel() : name(nullptr), rooms(0), reserved_rooms(0), grade(0.0f) {}
    Hotel(const char* nazwa, int pokoje, float ocena) {
        name = new char[strlen(nazwa) + 1];
        strcpy(name, nazwa);
        rooms = pokoje;
        grade = ocena;
    }

    ~Hotel() {
        delete[] name;
    }

    void reserveRoom() {
        if(reserved_rooms < rooms) {
            reserved_rooms++;
        }
        else {
            cout << "Brak wolnych pokoi" << endl;
        }
    }

    void cancelReservation() {
        if(reserved_rooms > 0) {
            reserved_rooms--;
        }
        else {
            cout << "Brak zarezerwowanych pokoi" << endl;
        }
    }

    float getRating() {
        return this->grade;
    }

    int getFreeRooms() {
        return this->rooms - this->reserved_rooms;
    }

    char *getName() {
        return name;
    }
};

bool sort_cond(Hotel *a, Hotel *b) {
    return a->getRating() > b->getRating();
}

int main() {
    int size = 3;
    Hotel *arr[size];
    arr[0] = new Hotel("hotel 1", 6, 3.5f);
    arr[1] = new Hotel("hotel 2", 4, 4.0f);
    arr[2] = new Hotel("hotel 3", 11, 4.8f);

    sort(arr, arr + size, sort_cond);
    for(int i = 0 ; i < size ; i++) {
        cout << arr[i]->getName() << "    " << arr[i]->getRating() << "    " << arr[i]->getFreeRooms() << endl;  
    }

    arr[0]->reserveRoom();
    arr[1]->reserveRoom();
    arr[2]->reserveRoom();
    cout << endl;

    for(int i = 0 ; i < size ; i++) {
        cout << arr[i]->getName() << "   " << arr[i]->getRating() << "    " << arr[i]->getFreeRooms() << endl;  
    }

    for(int i = 0 ; i < size ; i++) {
        delete arr[i];
    }
    return 0;
}