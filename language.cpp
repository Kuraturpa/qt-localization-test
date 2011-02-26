#include "language.h"
#include <iostream>

Language::Language(QApplication* a)
{
    this->app = a;
    this->ts = new QTranslator();
    languages<<"suomi.qm";
    languages<<"english.qm";
}

Language::~Language()
{
    std::clog<<"Language::~Language()"<<std::endl;
    delete ts;
}

void Language::ChangeLanguage(const int num)
{
    std::clog<< "Language::ChangeLanguage(" << num << ")" << std::endl;
    if(num > languages.size())
        return;
    ts->load(languages[num]);
    this->app->installTranslator(ts);
}
