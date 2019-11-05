#ifndef SCHEBRA_H
#define SCHERBA_H

#include <QWidget>
#include <QAbstractButton>

#include "ui_scherba.h"

namespace Ui {
class scherba;
}

class scherba : public QWidget
{
    Q_OBJECT

public:
    explicit scherba(QWidget *parent = nullptr);
    ~scherba();

public:
    Ui::scherba *ui;
public slots:
    void recieveData(QString str);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_buttonBox_accepted();
};

#endif // scherba_H
