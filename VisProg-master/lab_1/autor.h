#ifndef AUTOR_H
#define AUTOR_H

#include <QDialog>

namespace Ui {
class Autor;
}

class Autor : public QDialog
{
    Q_OBJECT

public:
    explicit Autor(QWidget *parent = 0);
    ~Autor();

private:
    Ui::Autor *ui;
};

#endif // AUTOR_H
