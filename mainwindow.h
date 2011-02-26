#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "language.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Language* lang;

public slots:
    void ChangeLanguage();
};

#endif // MAINWINDOW_H
