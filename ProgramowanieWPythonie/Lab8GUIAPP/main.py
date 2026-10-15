import sys
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QPushButton, QVBoxLayout,
    QLabel, QHBoxLayout, QWidget, QLineEdit
)

from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
import numpy as np
import matplotlib.pyplot as plt

class MplCanvas(FigureCanvas):
    def __init__(self, parent=None, width = 5, height = 4, dpi=100):
        fig = Figure(figsize=(width, height), dpi = dpi)
        self.axes = fig.add_subplot(111)
        super().__init__(fig)

class MainWindow(QMainWindow):
    funcs = [
                (0.01, lambda x, y: (0, 0.16 * y)),
                (0.08, lambda x, y: (0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6)),
                (0.15, lambda x, y: (-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44)),
                (1.00, lambda x, y: (0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6))
        ]
    
    def __init__(self):
        super().__init__()
        
        # Main window
        self.setWindowTitle("Fractal APP")
        self.centralWidget = QWidget()
        
        #layouts
        self.main_layout = QVBoxLayout(self.centralWidget)
        self.top_layout = QHBoxLayout()
        self.bottom_layout = QHBoxLayout()
        
        # iteration label
        self.iterations_label = QLabel("Iterations")
        self.top_layout.addWidget(self.iterations_label)
        
        # Text 
        self.text_place = QLineEdit()
        self.top_layout.addWidget(self.text_place)
        
        # Push button
        self.button = QPushButton("Start")
        self.top_layout.addWidget(self.button)
        self.button.clicked.connect(self.create_fractal)
        
        # Add plot 
        self.iterations = 100000
        self.canvas = MplCanvas(self, width=4, height=8, dpi=100)
        self.bottom_layout.addWidget(self.canvas)
        
        # Add layouts to main layout
        self.main_layout.addLayout(self.top_layout)
        self.main_layout.addLayout(self.bottom_layout)
        self.setCentralWidget(self.centralWidget)
        
        
    def get_iterations(self):
        text = self.text_place.text()
        self.iterations = int(text)
        
        
    def create_fractal(self):
        self.get_iterations()
        x = np.zeros(self.iterations + 1)
        y = np.zeros(self.iterations + 1)

        for i in range(self.iterations):
            rand = np.random.rand()
            for p, func in self.funcs:
                if rand < p:
                    x[i + 1], y[i + 1] = func(x[i], y[i])
                    break
        self.canvas.axes.clear()
        self.canvas.axes.scatter(x, y, s=0.1, color="green")
        self.canvas.draw()




app = QApplication(sys.argv)


window = MainWindow()
window.show()

sys.exit(app.exec_())        
        
    
    