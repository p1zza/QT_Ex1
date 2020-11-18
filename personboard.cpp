// Подключаем заголовочный файл класса
#include "personboard.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

PersonBoard::PersonBoard()
{
}

int PersonBoard::personCount() const
{
  return persons.size();
}

const Person* PersonBoard::getPersonConst(int index) const
{
  return &persons[index];
}

Person* PersonBoard::getPerson(int index)
{
  return &persons[index];
}

void PersonBoard::addPerson()
{
  persons.append(Person());
}

void PersonBoard::saveToJson(QString path)
{
    QFile file(path);
    QJsonDocument JsonDocument;
    QJsonObject jsonObj;
    QJsonArray jsonArray;
    for(int i = 0; i < persons.count(); i++)
    {
        jsonObj.insert("Numerator", persons[i].getNumerator());
        jsonObj.insert("Name", persons[i].getName());
        jsonObj.insert("PhoneNumber", persons[i].getPhoneNumber());
        jsonArray.append(jsonObj);
    }
    JsonDocument.setArray(jsonArray);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close();
}

void PersonBoard::loadFromJson(QString path)
{
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QString str = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument JsonDoc = QJsonDocument::fromJson(str.toUtf8(),&jsonError);
        if (jsonError.error != QJsonParseError::NoError)
        {
            //qDebug() << jsonError.errorString();
        }

        //QJsonArray rootArray = JsonDoc.array();
        const QJsonArray rootArray = JsonDoc.array();
        //QVariantList s = rootArray.toVariantList();
        for (int i = 0; i < rootArray.size(); i++)
        {
            Person tempPersVector;

            QJsonObject jsonObj = rootArray[i].toObject();
            tempPersVector.setNumerator(jsonObj.value("Numerator").toString());
            tempPersVector.setName(jsonObj.value("Name").toString());
            tempPersVector.setPhoneNumber(jsonObj.value("PhoneNumber").toString());

            persons.append(tempPersVector);
        }
        file.close();
}

void PersonBoard::removePerson(int index)
{
    persons.removeAt(index);
}
