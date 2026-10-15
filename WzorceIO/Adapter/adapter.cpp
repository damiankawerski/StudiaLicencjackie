#include <iostream>
#include <memory>

using namespace std;


class IPrinter {
public:
    virtual void print() = 0;
    virtual ~IPrinter() = default;
};


class OldPrinter{
public:
    void oldPrint() {
        cout << "Old printer: printing";
    }
};



class PrinterAdapter : public IPrinter {
private:
    shared_ptr<OldPrinter> oldPrinter;
public:

    PrinterAdapter(shared_ptr<OldPrinter> old) : oldPrinter(old) {}

    void print() {
        this->oldPrinter->oldPrint();
    }
};


int main() {
    shared_ptr<OldPrinter> legacyPrinter = make_shared<OldPrinter>();
    shared_ptr<IPrinter> printer = make_shared<PrinterAdapter>(legacyPrinter);

    printer->print();  
    return 0;
}