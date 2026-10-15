#include <iostream>
#include <memory>

class Game {
public:
    void play() {
        initialize();
        startPlay();
        endPlay();
    }

    virtual ~Game() = default;

protected:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;
};

class Chess : public Game {
protected:
    void initialize() override {
        std::cout << "Inicjalizacja szachów.\n";
    }

    void startPlay() override {
        std::cout << "Szachy się rozpoczęły.\n";
    }

    void endPlay() override {
        std::cout << "Szachy zakończone.\n";
    }
};

class Football : public Game {
protected:
    void initialize() override {
        std::cout << "Ustawiamy bramki i dmuchamy piłkę.\n";
    }

    void startPlay() override {
        std::cout << "Mecz rozpoczęty!\n";
    }

    void endPlay() override {
        std::cout << "Koniec meczu, idziemy na browara.\n";
    }
};

int main() {
    std::unique_ptr<Game> game;

    game = std::make_unique<Chess>();
    game->play();

    std::cout << "------------------\n";

    game = std::make_unique<Football>();
    game->play();

    return 0;
}
