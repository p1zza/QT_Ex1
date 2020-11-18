#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
private:
    QString Number;
    QString Name;
    QString PhoneNumber;
public:
    Person();
    QString getNumerator() const;
    QString getName() const;
    QString getPhoneNumber()const;

    void setNumerator(QString num);
    void setName(QString name);
    void setPhoneNumber(QString pn);
};

#endif // PERSON_H
