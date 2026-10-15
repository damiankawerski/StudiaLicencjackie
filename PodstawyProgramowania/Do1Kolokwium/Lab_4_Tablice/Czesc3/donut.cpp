#include <ncurses.h>
#include <cmath>
#include <thread>
#include <chrono>

const int width = 80;
const int height = 24;
const float PI = 3.14159265f;
const float A = 0.8f;
const float B = 2.0f;

void clearScreen() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            mvaddch(y, x, ' ');
        }
    }
}

void render() {
    const float sA = std::sin(A);
    const float cA = std::cos(A);
    const float sB = std::sin(B);
    const float cB = std::cos(B);

    clearScreen();

    float zBuffer[width][height];
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            zBuffer[x][y] = 0;
        }
    }

    for (float theta = 0; theta < 2 * PI; theta += 0.07) {
        const float st = std::sin(theta);
        const float ct = std::cos(theta);
        for (float phi = 0; phi < 2 * PI; phi += 0.03) {
            const float sp = std::sin(phi);
            const float cp = std::cos(phi);

            const float ch = ct * cB * (sp * sA + st * cA * cp) - st * sB;
            const float h = ct * cB * (st * sA - sp * cA * cp) + ct * sB;
            const float l = ch * A + h * B;

            if (l > 0) {
                const int x = width / 2 + static_cast<int>(40 * l * st / (1 + h * A - ch * B));
                const int y = height / 2 + static_cast<int>(12 * l * h / (1 + h * A - ch * B));
                const int ooz = static_cast<int>(1000 / (1 + h * A - ch * B));

                if (x >= 0 && x < width && y >= 0 && y < height && ooz > zBuffer[x][y]) {
                    zBuffer[x][y] = ooz;
                    mvaddch(y, x, ".,-~:;=!*#$@"[static_cast<int>(l) % 10]);
                }
            }
        }
    }

    refresh();
}

int main() {
    initscr();
    curs_set(0);  // Hide the cursor
    nodelay(stdscr, TRUE);  // Non-blocking input

    while (true) {
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    endwin();  // End ncurses mode

    return 0;
}
