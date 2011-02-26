#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <QObject>
//#include <QString>

class Language : public QObject
{
    Q_OBJECT
public:
    explicit Language(QObject *parent = 0);
    void ChangeLanguage(const int);


};

#endif // LANGUAGE_H
