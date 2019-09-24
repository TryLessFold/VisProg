#ifndef SDIPROGRAM_H
#define SDIPROGRAM_H

#include<QMainWindow>
#include<QtWidgets>
#include<DocWindow.h>

class SDIProgram: public QMainWindow
{
    Q_OBJECT
public:
    SDIProgram(QWidget *pwgt = 0): QMainWindow(pwgt)
    {
        QMenu *pmnuFile = new QMenu("&File");
        QMenu *pmnuHelp = new QMenu("&Help");
        DocWindow_Scherba *pdoc = new DocWindow_Scherba;
        pmnuFile->addAction("&Open...", pdoc, SLOT(slotLoad()), QKeySequence("CTRL+O"));

    }
}
#endif // SDIPROGRAM_H
