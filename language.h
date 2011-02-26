#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <QObject>
#include <QApplication>
#include <QTranslator>
#include <QStringList>
//#include <QString>

class Language : public QObject
{
    Q_OBJECT
public:
    Language(QApplication*);
    ~Language();
    void ChangeLanguage(const int);
private:
    QApplication* app;
    QTranslator* ts;
    QStringList languages;

};

#endif // LANGUAGE_H
