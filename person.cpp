#include "person.h"

Person::Person()
{

}

QString Person::getNumerator() const
{
    return Number;
}

QString Person::getName() const
{
    return Name;
}

QString Person::getPhoneNumber() const
{
    return PhoneNumber;
}

void Person::setName(QString name)
{
    Name = name;
}
void Person::setNumerator(QString num)
{
    Number = num;
}
void Person::setPhoneNumber(QString pn)
{
    PhoneNumber = pn;
}



