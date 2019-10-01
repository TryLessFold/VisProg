#include "DocWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QColorDialog>

DocWindow_Scherba::DocWindow_Scherba(QWidget* pwgt): QTextEdit(pwgt)
{

}

void DocWindow_Scherba::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()){
        return;
    }
    QFile file(str);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
        m_strFileName=str;
        emit changeWindowTitle(m_strFileName);
    }
}

void DocWindow_Scherba::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if(!str.isEmpty())
    {
        m_strFileName=str;
        slotSave();
    }
}

void DocWindow_Scherba::slotSave()
{
    if (m_strFileName.isEmpty()){
        slotSaveAs();
        return;
    }
    QMessageBox::information(0, "Progress", "Succesful!");
    QFile file(m_strFileName);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream(&file)<<toPlainText();
        file.close();
        emit changeWindowTitle(m_strFileName);
    }
}

void DocWindow_Scherba::slotTextColor(){
    QColor str = QColorDialog::getColor();
    setTextColor(str);
}
