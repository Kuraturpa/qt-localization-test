// -- -- -- -- -- -- -- -- --
/*
    Tekijä: Joonas Ruotsalainen
    Email: joo.ruot@gmail.com
    Tiedosto: language.h
    Luotu: 2011-02-24

    Kuvaus:
            header file

*/
// -- -- -- -- -- -- -- -- --

#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <QObject>
#include <QApplication>
#include <QTranslator>
#include <QString>

class Language : public QObject
{
    Q_OBJECT
public:
    Language(QApplication*);
    ~Language();
    void ChangeLanguage(const QString);
private:
    QApplication* app;
    QTranslator* ts;

};

#endif // LANGUAGE_H
