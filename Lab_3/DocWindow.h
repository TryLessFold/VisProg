#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include <QTextEdit>

class DocWindow_Scherba: public QTextEdit
{
    Q_OBJECT
private:
    QString m_strFileName;
public:
    DocWindow_Scherba(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotTextColor();
};

#endif // DOWCWINDOW_H
