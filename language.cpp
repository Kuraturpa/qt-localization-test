// -- -- -- -- -- -- -- -- --
/*
    Tekijä: Joonas Ruotsalainen
    Email: joo.ruot@gmail.com
    Tiedosto: language.cpp
    Luotu: 2011-02-24

    Kuvaus:
            Kielen vaihtamisen toiminnallisuus
*/
// -- -- -- -- -- -- -- -- --

#include "language.h"
#include <iostream>

Language::Language(QApplication* a)
{
    this->app = a;
    ts = new QTranslator();
    if(!ts)
        return;
}

Language::~Language()
{
    std::clog<<"Language::~Language()"<<std::endl;
    delete ts;
}

void Language::ChangeLanguage(const QString file)
{
    std::clog<< "Language::ChangeLanguage(" << file.toStdString() << ")" << std::endl;
    if(!ts->load(file))
        std::clog<<"Can't open language file."<<std::endl;
    this->app->installTranslator(ts);
}
