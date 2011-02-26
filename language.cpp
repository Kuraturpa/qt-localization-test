#include "language.h"
#include <iostream>
#include <QObject>
#include <QVariant>
#include <QApplication>
#include <QTranslator>
//#include <QString>

Language::Language(QApplication* a)
{
    this->app = a;
    this->ts = new QTranslator();
}

Language::~Language()
{
    std::clog<<"Language::~Language()"<<std::endl;
    delete ts;
}

void Language::ChangeLanguage(const int num)
{
    std::clog<< "Language::ChangeLanguage(" << num << ")" << std::endl;
    if(num == 0)
        ts->load("suomi.qm");
    else
        ts->load("english.qm");
    this->app->installTranslator(ts);
}
