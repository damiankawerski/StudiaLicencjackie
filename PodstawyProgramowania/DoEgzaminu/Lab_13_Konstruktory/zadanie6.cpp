#include <iostream>
using namespace std;


class List {
private:
    struct Node {
        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    int length;

public:
    List() : head(nullptr), length(0) {}

    ~List() {
        clear();
    }

    List(const List& other) {}

    int size() {
        return length;
    }

    int& at(int i) {
        Node* current = head;
        for(int j = 0 ; j < i ; j++) {
            current = current->next;
        }
        return current->data;
    }

    int* find(int v) {
        Node* current = head;
        for(int i = 0 ; i < length ; i++) {
            if(v == current->data) {
                return &current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    void append(int v) {
        Node* newNode = new Node(v);
        if(head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }

    void insert(int i, int v) {
        Node *newNode = new Node(v);
        if(i == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node *current = head;
            for(int j = 0 ; j < i ; j++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        length++;
    }

    void remove(int i) {
        Node *temp;

        if(i == 0) {
            temp = head;
            head = head->next;
        } else {
            Node *current = head;
            for(int j = 0 ; j < i ; j++) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
        }

        delete temp;
        --length;
    }

    void clear() {
        while(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        length = 0;
    }

};

int main() {
    List myList;
    myList.append(3);
    myList.append(2);
    myList.append(1);

    cout << "list size: " << myList.size() << endl;

    for(int i = 0 ; i < myList.size() ; i++) {
        cout << myList.at(i) << " ";
    }
    cout << endl;

    return 0;
}