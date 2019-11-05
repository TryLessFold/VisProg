#include "scherba.h"
#include "ui_scherba.h"
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include <QMessageBox>

scherba::scherba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scherba)
{
    ui->setupUi(this);
}

void scherba::recieveData(QString str)
{
    QStringList lst = str.split("*");
    ui->textEdit->setText(lst.at(1) + "\n" + lst.at(0));
    if (lst.size() > 1) {
        QImage image1(lst.at(0));
        ui->label->setPixmap(QPixmap::fromImage(image1));
    }
}

scherba::~scherba()
{
    delete ui;
}

void scherba::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text() == "Reset") {
        ui->textEdit->clear();
        ui->label->clear();

    }
    else if (button->text() == "Open") {
        QString filename = QFileDialog::getOpenFileName(nullptr, "Открыть", QDir::currentPath());
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream stream(&file);
            ui->textEdit->setText(stream.readAll());
            file.close();
        }
        QStringList inf = ui->textEdit->toPlainText().split("\n");
        QImage image2(inf.at(5));
        ui->label->setPixmap(QPixmap::fromImage(image2));
    }
    else
    {
        QString filename = QFileDialog::getSaveFileName(nullptr, "Сохранить ", QDir::currentPath());
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream(&file) << ui->textEdit->toPlainText();
            file.close();
            QMessageBox::information(this, "Файл сохранён", "Файл успешно сохранён");
        }

    }
}

void scherba::on_buttonBox_accepted()
{
//    QString filename = QFileDialog::getSaveFileName(nullptr, "Сохранить ", QDir::currentPath());
//    QFile file(filename);
//    if (file.open(QIODevice::WriteOnly)) {
//        QTextStream(&file) << ui->textEdit->toPlainText();
//        file.close();
//        QMessageBox::information(this, "Файл сохранён", "Файл успешно сохранён");
//    }
}
