#ifndef STARTDIALOGSCHERBA_H
#define STARTDIALOGSCHERBA_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputDialogScherba.h"

class startDialogScherba: public QPushButton {
    Q_OBJECT

public:
    startDialogScherba(QWidget* pwgt = 0) : QPushButton("Press", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
        inputDialogScherba* pInputDialog = new inputDialogScherba;
        if (pInputDialog->exec()==QDialog::Accepted) {
            QMessageBox::information(0, "Your info: ", "Name:" + pInputDialog->firstName() + "\nLast Name:"
                                     + pInputDialog->lastName());
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOGSCHERBA_H
