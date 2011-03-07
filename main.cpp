// -- -- -- -- -- -- -- -- --
/*
    Tekijä: Joonas Ruotsalainen
    Email: joo.ruot@gmail.com
    Tiedosto: main.cpp
    Luotu: 2011-02-24

    Kuvaus:
            Qt-lokalisoinnin testiohjelma, jossa dynaaminen kielen vaihtaminen.
*/
// -- -- -- -- -- -- -- -- --

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(&a);
    w.show();
    return a.exec();
}
