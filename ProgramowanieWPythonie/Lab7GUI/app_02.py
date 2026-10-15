import sys
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QPushButton, QVBoxLayout,
    QLabel, QLineEdit, QWidget
)


class MainWindow(QMainWindow):
    
    def __init__(self):
        super().__init__()
        
        self.setWindowTitle("Moja Aplikacja")
        
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)  
        
        self.layout = QVBoxLayout()
        
        self.button = QPushButton("Oblicz")
        self.layout.addWidget(self.button)
        self.button.clicked.connect(self.nacisniety)
        
        self.label = QLabel("Etykieta")
        self.layout.addWidget(self.label)
        
        self.linia = QLineEdit()
        self.linia.setPlaceholderText("Wprowadź tekst") 
        self.layout.addWidget(self.linia)
        
        self.central_widget.setLayout(self.layout)  
        
    def nacisniety(self):
        text = self.linia.text()
        
        counter = 0
        
        counter += text.count('c')
        counter += text.count('g')
        
        procenty = counter / len(text) * 100
        
        self.label.setText(f"% G i C: {procenty:.2f}%")
        
app = QApplication(sys.argv)

window = MainWindow()
window.show()

sys.exit(app.exec_()) 
