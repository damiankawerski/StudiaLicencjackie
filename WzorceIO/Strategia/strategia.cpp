#include <iostream>

using namespace std;


class Verification {
public:
    virtual ~Verification() = default;
    virtual bool verify(const string& userId) = 0;
};

class SMSVerification : public Verification {
public:
    bool verify(const string& userId) override {
        std::cout << "Wysyłam SMS do użytkownika " << userId << "...\n";
        return true;
    }
};

class EmailVerification : public Verification {
public:
    bool verify(const string& userId) override {
        std::cout << "Wysyłam e-mail weryfikacyjny do " << userId << "...\n";
        return true;
    }
};

class BankVerification : public Verification {
public:
    bool verify(const std::string& userId) override {
        std::cout << "Logowanie do banku dla " << userId << "...\n";
        return true; // oczywiście tu normalnie byłoby API banku
    }
};

class Authenticator{
private:
    Verification* registerMethod;
public:
    void setVerification(Verification* ver) {
        this->registerMethod = ver;
    }

    void registerUser(const string& userId) {
        std::cout << "Rozpoczynam rejestrację dla: " << userId << std::endl;
        if (registerMethod && registerMethod->verify(userId)) {
            std::cout << "Weryfikacja zakończona sukcesem. Konto utworzone.\n";
        } else {
            std::cout << "Weryfikacja nie powiodła się. Rejestracja przerwana.\n";
        }
    }
};


int main() {
    Authenticator auth;

    SMSVerification sms;
    EmailVerification email;
    BankVerification bank;

    // Rejestracja przez SMS
    auth.setVerification(&sms);
    auth.registerUser("jan.kowalski");

    // Rejestracja przez e-mail
    auth.setVerification(&email);
    auth.registerUser("ania.nowak");

    // Rejestracja przez bank
    auth.setVerification(&bank);
    auth.registerUser("zbigniew.nowakowski");

    return 0;
}
