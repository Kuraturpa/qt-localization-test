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

void Language::ChangeLanguage(const int num)
{
    std::clog<< "Language::ChangeLanguage(" << num << ")" << std::endl;
}
