import sys
import random
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtGui import QPainter, QColor
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget


CELL_SIZE = 20
BOARD_WIDTH = 40
BOARD_HEIGHT = 30
FOOD_COUNT = 200  # ILE JEDZENIA NA PLANSZY


class SnakeGame(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setFixedSize(BOARD_WIDTH * CELL_SIZE, BOARD_HEIGHT * CELL_SIZE)
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.game_loop)
        self.setFocusPolicy(Qt.StrongFocus)
        self.init_game()

    def init_game(self):
        self.snake = [(5, 5), (4, 5), (3, 5)]
        self.direction = (1, 0)
        self.food = []
        self.spawn_food(FOOD_COUNT)
        self.timer.start(100)

    def spawn_food(self, count=1):
        for _ in range(count):
            while True:
                f = (
                    random.randint(0, BOARD_WIDTH - 1),
                    random.randint(0, BOARD_HEIGHT - 1),
                )
                if f not in self.snake and f not in self.food:
                    self.food.append(f)
                    break

    def game_loop(self):
        head_x, head_y = self.snake[0]
        dx, dy = self.direction
        new_head = (head_x + dx, head_y + dy)

        if (
            new_head in self.snake or
            not 0 <= new_head[0] < BOARD_WIDTH or
            not 0 <= new_head[1] < BOARD_HEIGHT
        ):
            self.timer.stop()
            print("Game Over")
            return

        self.snake.insert(0, new_head)

        if new_head in self.food:
            self.food.remove(new_head)
            self.spawn_food()  # dodaj jedno nowe, żeby było cały czas 15
        else:
            self.snake.pop()

        self.update()

    def keyPressEvent(self, event):
        key = event.key()
        if key in (Qt.Key_Up, Qt.Key_W) and self.direction != (0, 1):
            self.direction = (0, -1)
        elif key in (Qt.Key_Down, Qt.Key_S) and self.direction != (0, -1):
            self.direction = (0, 1)
        elif key in (Qt.Key_Left, Qt.Key_A) and self.direction != (1, 0):
            self.direction = (-1, 0)
        elif key in (Qt.Key_Right, Qt.Key_D) and self.direction != (-1, 0):
            self.direction = (1, 0)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setBrush(QColor(0, 255, 0))
        for x, y in self.snake:
            painter.drawRect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE)

        painter.setBrush(QColor(255, 0, 0))
        for fx, fy in self.food:
            painter.drawRect(fx * CELL_SIZE, fy * CELL_SIZE, CELL_SIZE, CELL_SIZE)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Snake na Obżarstwie")
        self.setCentralWidget(SnakeGame(self))


app = QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec())
