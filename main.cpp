#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "registerdialog.h"
#include "mainwindow.h"
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     MainWindow w;
     if (w.login->exec() == QDialog::Accepted)
        w.show();
     return a.exec();

}
