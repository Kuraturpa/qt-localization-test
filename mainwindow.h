// -- -- -- -- -- -- -- -- --
/*
    Tekijä: Joonas Ruotsalainen
    Email: joo.ruot@gmail.com
    Tiedosto: mainwindow.h
    Luotu: 2011-02-24

    Kuvaus:
            header file

*/
// -- -- -- -- -- -- -- -- --

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
    explicit MainWindow(QApplication*,QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Language* lang;
    QApplication* app;

public slots:
    void ChangeLanguage();
    void OpenDialog();
};

#endif // MAINWINDOW_H
