#ifndef BOARDVIEW_H
#define BOARDVIEW_H



#include <QFile>
#include "person.h"


class PersonBoard
{
private:
  QVector<Person> persons;

public:
    PersonBoard();
    int personCount() const;
    const Person* getPersonConst(int index) const;
    Person* getPerson(int index);
    void addPerson();
    void saveToJson(QString path);
    void loadFromJson(QString path);
    void removePerson(int index);
};
#endif // BOARDVIEW_H
