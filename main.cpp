#include <QtGui/QApplication>
#include "mainwindow.h"
#include "qrichtextbox.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRichTextBox textBox;
    MainWindow w;
    textBox.show();
    w.show();
    
    return a.exec();
}
