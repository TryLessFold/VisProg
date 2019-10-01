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
        pmnuFile->addAction("&Save...", pdoc, SLOT(slotSave()), QKeySequence("CTRL+S"));
        pmnuFile->addAction("&Save as...", pdoc, SLOT(slotSaveAs()), QKeySequence("CTRL+A"));
        pmnuFile->addAction("&Color...", pdoc, SLOT(slotTextColor()), QKeySequence("CTRL+C"));
        pmnuFile->addSeparator();
        pmnuFile->addAction("&Quit", qApp, SLOT(quit()), QKeySequence("CTRL+E"));
        pmnuHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);
        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);
        setCentralWidget(pdoc);
        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready", 2000);
    }
public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "About", "Scherba IP-711");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }
};
#endif // SDIPROGRAM_H
