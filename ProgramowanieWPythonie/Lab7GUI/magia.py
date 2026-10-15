import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QPushButton, QVBoxLayout,
    QLabel, QLineEdit, QWidget, QHBoxLayout, QSlider, 
)


class MainWindow(QMainWindow):
    
    def __init__(self):
        super().__init__()
        
        #Main windows
        self.setWindowTitle("Suwaczek i guziczek")
        self.central_widget = QWidget()
        #layouts
        self.main_layout = QVBoxLayout(self.central_widget)
        self.top_layout = QHBoxLayout()
        self.bottom_layout = QHBoxLayout()
        #Tutaj cos 

        self.label_1 = QLabel("Suwak")
        self.top_layout.addWidget(self.label_1)
        
        self.slider = QSlider(Qt.Horizontal)
        self.slider.setRange(0,100)
        self.slider.setValue(50)
        self.slider.valueChanged.connect(self.update_label)
        self.top_layout.addWidget(self.slider)
        self.label_2 = QLabel("[50]")
        self.top_layout.addWidget(self.label_2)

        #Add layouts to main
        self.main_layout.addLayout(self.top_layout)
        self.main_layout.addLayout(self.bottom_layout)
        self.setCentralWidget(self.central_widget)
        #Rest
        
    def update_label(self, value):
        self.label_2.setText((str(value))) 
        


app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec_()) 
