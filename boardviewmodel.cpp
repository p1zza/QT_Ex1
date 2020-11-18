#include "boardviewmodel.h"
#include <QMessageBox>

int BoardViewModel::rowCount(const QModelIndex &parent) const
{
  return personBoard.personCount();
}

int BoardViewModel::columnCount(const QModelIndex &parent) const
{
  return 3;
}

QVariant BoardViewModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
      return QVariant();

  const Person* person = personBoard.getPersonConst(index.row());
  if (role == Qt::DisplayRole || role == Qt::EditRole)
      switch (index.column())
      {
          case 0: return person->getNumerator();
          break;

          case 1 : return person->getName();
          break;

          case 2 : return person->getPhoneNumber();
          break;

          default: return QVariant();
          break;
      }
    return QVariant();
}

bool BoardViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
      Person* person = personBoard.getPerson(index.row());
      switch(index.column())
      {
        case 0: person->setNumerator(value.toString());
          break;
        case 1 : person->setName(value.toString());
          break;
        case 2: person->setPhoneNumber(value.toString());
          break;
        default:return false;
      }
  }
  else
  {
      return true;
  }
}

QVariant BoardViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole)
      return QVariant();


  if (orientation == Qt::Horizontal)
  {
    QStringList headers;
    headers << "Номер" << "Имя" << "Телефон";
    return headers[section];
  }
  else
      return QString("%1").arg(section + 1);
}

Qt::ItemFlags BoardViewModel::flags(const QModelIndex &index) const
{
  if (!index.isValid())
      return Qt::ItemIsEnabled;
  return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}


void BoardViewModel::addPerson()
{
  beginInsertRows(QModelIndex(), 0, 0);
  personBoard.addPerson();
  endInsertRows();
}

void BoardViewModel::saveToJson(QString path)
{
  personBoard.saveToJson(path);
}

void BoardViewModel::loadFromJson(QString path)
{
  personBoard.loadFromJson(path);
  update();
}

void BoardViewModel::del(QList<int> rows)
{
  for(int i = rows.count() -1 ; i >=0; i--)
  {
    personBoard.removePerson(rows[i]);
  }
    update();
}

void BoardViewModel::update()
{
  beginResetModel();
  endResetModel();
}
