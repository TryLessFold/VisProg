#include "mainwindow.h"
#include <QApplication>
#include "startDialogScherba.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startDialogScherba startDialog;
    startDialog.show();

    return a.exec();
}
