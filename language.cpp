#include "language.h"
#include <iostream>
#include <QObject>
#include <QVariant>
#include <QApplication>
//#include <QString>

Language::Language(QObject *parent) :
            QObject(parent)
{

}

void Language::ChangeLanguage()
{
    //std::clog<< "Language::ChangeLanguage(" << name.toStdString() << ")" << std::endl;
    std::clog<< "Language::ChangeLanguage()" << std::endl;
}
