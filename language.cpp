#include "language.h"
#include <iostream>

Language::Language(QApplication* a)
{
    this->app = a;
    this->ts = new QTranslator();
    if(!ts)
        return;
    languages<<"suomi.qm";
    languages<<"english.qm";
    languages<<"lorem.qm";
}

Language::~Language()
{
    std::clog<<"Language::~Language()"<<std::endl;
    delete ts;
}

void Language::ChangeLanguage(const int num)
{
    std::clog<< "Language::ChangeLanguage(" << num << ")" << std::endl;
    if(num >= languages.size())
        return;
    if(!ts->load(languages[num]))
        std::clog<<"Can't find language file."<<std::endl;
    this->app->installTranslator(ts);
}
