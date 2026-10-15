#include <iostream>
#include <queue>
#include <memory>
#include <string>

using namespace std;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};


class Printer {
public:
    void printDocument(const std::string& doc) {
        cout << "Drukowanie dokumentu: " << doc << std::endl;
    }

    void cancelDocument(const std::string& doc) {
        cout << "Anulowano dokument: " << doc << std::endl;
    }
};

class PrintCommand : public Command {
private:
    Printer* printer;
    string document;
public:
    PrintCommand(Printer* p, const std::string& doc) : printer(p), document(doc) {}

    void execute() override {
        printer->printDocument(document);
    }
};


class CancelCommand : public Command {
private:
    Printer* printer;
    string document;
public:
    CancelCommand(Printer* p, const std::string& doc) : printer(p), document(doc) {}

    void execute() override {
        printer->cancelDocument(document);
    }
};

class CommandQueue {
private:
    queue<unique_ptr<Command>> commands;
public:
    void addCommand(unique_ptr<Command> cmd) {
        commands.push(move(cmd));
    }

    void run() {
        while (!commands.empty()) {
            commands.front()->execute();
            commands.pop();
        }
    }
};


int main() {
    Printer printer;
    CommandQueue queue;


    queue.addCommand(std::make_unique<PrintCommand>(&printer, "Raport.pdf"));
    queue.addCommand(std::make_unique<PrintCommand>(&printer, "Faktura.docx"));
    queue.addCommand(std::make_unique<CancelCommand>(&printer, "Faktura.docx"));


    queue.run();

    return 0;
}

