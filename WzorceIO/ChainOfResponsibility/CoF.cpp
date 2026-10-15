#include <iostream>
#include <memory>
#include <string>

enum class LogLevel {
    DEBUG,
    INFO,
    ERROR
};

class Handler {
protected:
    std::shared_ptr<Handler> next;

public:
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> nextHandler) {
        next = nextHandler;
    }

    virtual void handle(LogLevel level, const std::string& message) {
        if (next)
            next->handle(level, message);
    }
};

class DebugHandler : public Handler {
public:
    void handle(LogLevel level, const std::string& message) override {
        if (level == LogLevel::DEBUG)
            std::cout << "[DEBUG] " << message << std::endl;
        else if (next)
            next->handle(level, message);
    }
};

class InfoHandler : public Handler {
public:
    void handle(LogLevel level, const std::string& message) override {
        if (level == LogLevel::INFO)
            std::cout << "[INFO] " << message << std::endl;
        else if (next)
            next->handle(level, message);
    }
};

class ErrorHandler : public Handler {
public:
    void handle(LogLevel level, const std::string& message) override {
        if (level == LogLevel::ERROR)
            std::cout << "[ERROR] " << message << std::endl;
        else if (next)
            next->handle(level, message);
    }
};

// Przykład użycia
int main() {
    auto debug = std::make_shared<DebugHandler>();
    auto info = std::make_shared<InfoHandler>();
    auto error = std::make_shared<ErrorHandler>();

    debug->setNext(info);
    info->setNext(error);

    // Łańcuch: debug -> info -> error
    debug->handle(LogLevel::INFO, "To jest informacja.");
    debug->handle(LogLevel::ERROR, "Wystąpił błąd!");
    debug->handle(LogLevel::DEBUG, "Debuguję...");

    return 0;
}
