from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5 import QtCore, QtGui, QtWidgets
import sys
from training import test
class btn(QPushButton):
    def __init__(self,Widget,text="",color="#fff"):
        super().__init__(Widget)
        self.setStyleSheet("QPushButton {\n"
"    background:rgba(0,0,0,0);\n"
"    border-color: rgba(0,0,0,0);\n"
"    font-size: 1.6rem;\n"
"    border: 1px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(0,0,0,.1);\n"
"    text-decoration: none;\n"
"}")
        self.setText(text)

class MainW(QWidget):
    _startPos = None
    _endPos = None
    _isTracking = False

    def __init__(self):
        super().__init__()
        self._initUI()

    def _initUI(self):
        self.setFixedSize(QSize(800, 460))
        self.setWindowFlags(Qt.FramelessWindowHint)  # 无边框
        self.bgm = QLabel(self)
        self.bgm.setGeometry(QtCore.QRect(0, 0, 800, 460))
        self.bgm.setStyleSheet("color:#FFF")
        self.bgm.setPixmap(QPixmap("img/bg2.jpg").scaled(self.bgm.width(),self.bgm.height()))
        self.top_bar = QLabel(self)
        self.top_bar.setGeometry(QtCore.QRect(0, 0, 800, 35))
        self.top_bar.setText("Bucket Launcher")
        self.top_bar.setStyleSheet("background-color:rgba(255,255,255,1);color:rgb(121,165,229);font-size:14px;font-family:Consolas")
        self.top_bar.setAlignment(Qt.AlignCenter)
        self.icon = QLabel(self)
        self.icon.setGeometry(QtCore.QRect(0, 0, 35, 35))
        self.icon.setStyleSheet("border-image: url(:/img/icon.png)")
        self.closebtn = btn(self,"×")
        self.closebtn.setGeometry(QtCore.QRect(800-35, 0, 35, 35))
        self.starbtn = btn(self,"Strat!")
        self.starbtn.setGeometry(QtCore.QRect(670, 370, 75, 23))
        self.starbtn.setStyleSheet("QPushButton {\n"
"    color: #fff;\n"
"    background-color: #5eb95e;\n"
"    border-color: #5eb95e;\n"
"    font-size: 1.6rem;\n"
"    border: 1px solid transparent;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4aaa4a;\n"
"}")
        self.closebtn.clicked.connect(QCoreApplication.instance().quit)

    def mouseMoveEvent(self, e: QMouseEvent):
    	if e.buttons () == QtCore.Qt.LeftButton and self._startPos != None:
	        self._endPos = e.pos() - self._startPos
	        self.move(self.pos() + self._endPos)

    def mousePressEvent(self, e: QMouseEvent):
        if e.button() == Qt.LeftButton:
            self._isTracking = True
            self._startPos = QPoint(e.x(), e.y())

    def mouseReleaseEvent(self, e: QMouseEvent):
        if e.button() == Qt.LeftButton:
            self._isTracking = False
            self._startPos = None
            self._endPos = None
# import rc_MainUI

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MainW()
    ex.show()
    sys.exit(app.exec_())