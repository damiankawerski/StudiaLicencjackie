#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <chrono>


class Schedule {
public:
    virtual void fetchAndDisplay() = 0;
    virtual ~Schedule() = default;
};


class MoriaSchedule : public Schedule {
    std::string studentId;
public:
    MoriaSchedule(const std::string& id) : studentId(id) {
        std::cout << "[MoriaSchedule] Inicjalizacja dla studenta: " << studentId << std::endl;
    }

    void fetchAndDisplay() override {
        std::cout << "[MoriaSchedule] Pobieranie planu z serwera..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));  // opoznienie bo api
        std::cout << "[MoriaSchedule] Plan zajęć dla " << studentId << ":\n";
        std::cout << " - Poniedziałek: Programowanie 8:00\n";
        std::cout << " - Wtorek: Algorytmy 10:00\n";
        std::cout << " - Środa: SI 12:00\n";
    }
};


class ScheduleProxy : public Schedule {
    std::string studentId;
    std::unique_ptr<MoriaSchedule> moriaSchedule;

public:
    ScheduleProxy(const std::string& id) : studentId(id) {}

    void fetchAndDisplay() override {
        if (!moriaSchedule) {
            std::cout << "[Proxy] Tworzenie prawdziwego obiektu planu zajęć...\n";
            moriaSchedule = std::make_unique<MoriaSchedule>(studentId);
        }
        moriaSchedule->fetchAndDisplay();
    }
};


int main() {
    Schedule* schedule = new ScheduleProxy("s123456");

    std::cout << "Proxy utworzony. Plan jeszcze nie pobrany.\n\n";

    std::cout << "Pierwsze żądanie planu:\n";
    schedule->fetchAndDisplay();

    std::cout << "\nDrugie żądanie planu:\n";
    schedule->fetchAndDisplay();

    delete schedule;
    return 0;
}