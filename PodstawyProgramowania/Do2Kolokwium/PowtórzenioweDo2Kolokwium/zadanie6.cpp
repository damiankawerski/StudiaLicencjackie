#include <iostream>
#include <cstring>
using namespace std;

struct player_stats {
    char username[13];
    int wins;
    int games;
    int elim;
    int rank;
};

void calculate_rank(char **rankings, player_stats *result, int size) {
    for(int i = 0 ; i < size ; i++) {
        char *token = strtok(rankings[i], ";");
        strcpy(result[i].username, token);

        token = strtok(nullptr, ";");
        result[i].wins = atoi(token);

        token = strtok(nullptr, ";");
        result[i].games = atoi(token);

        token = strtok(nullptr, ";");
        result[i].elim = atoi(token);

        result[i].rank = result[i].wins + result[i].games + result[i].elim;
    }
}


void displayRanking(const player_stats* result, int numPlayers) {
    std::cout << "Ranking:\n";
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Player: " << result[i].username << ", Ranking Score: " << result[i].rank << std::endl;
    }
}

int main() {

     const char* input[] = {
        "MystiqueHero;1365;6890;15210",
        "Frizz;5400;6200;11000",
        "Ziemniak;9965;11000;73000",
        "Evel00na;10;10;90"
    };

    int size = sizeof(input) / sizeof(input[0]);

    char **rankings = new char*[size];
    for(int i = 0 ; i < size ; i++) {
        rankings[i] = new char[strlen(input[i]) + 1];
        strcpy(rankings[i], input[i]);
    }

    player_stats* result = new player_stats[size];

    calculate_rank(rankings, result, size);
    displayRanking(result, size);


    for(int i = 0 ; i < size ; i++) {
        delete[] rankings[i];
    }
    delete[] rankings;
    delete[] result;
    return 0;
}