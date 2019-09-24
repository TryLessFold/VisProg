#ifndef INPUTDIALOGSCHERBA_H
#define INPUTDIALOGSCHERBA_H

#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class inputDialogScherba: public QDialog
{
    Q_OBJECT
private:
    QLineEdit * m_ptxtFirstName;
    QLineEdit * m_ptxtLastName;
public:
    inputDialogScherba(QWidget* pwfgt = 0);

    QString firstName();
    QString lastName();
};

#endif // INPUTDIALOGSCHERBA_H
