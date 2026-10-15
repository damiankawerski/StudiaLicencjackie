#include <iostream>
using namespace std;


enum internet{
    connected,
    disconnected,
    connecting
};

struct computer {
    internet state;
    const char *IP;
    const char *owner;
};

const char* enumToString(internet status) {
    switch(status) {
        case connected:
        return "connected";
        case connecting:
        return "connecting";
        case disconnected:
        return "disconnected";
        default:
        return "zły input";
    }
}

void show_status(computer data) {
    cout << data.owner << endl;
    cout << data.IP << endl;
    cout << enumToString(data.state) << endl;
}

int main() {
    computer data;
    data.IP = "192.168.0.1";
    data.owner = "Jakub Tracz Pracz";
    data.state = connected;
    show_status(data);
    return 0;
}