#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include "personboard.h"

class BoardViewModel: public QAbstractTableModel
{
    private:
    PersonBoard personBoard;

    public:

    BoardViewModel(QObject *parent = 0) : QAbstractTableModel(parent) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant tableData(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QVariant data(const QModelIndex &index, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    void addPerson();

    void saveToJson(QString path);

    void loadFromJson(QString path);

    void del(QList<int> rows);

    void update();
};

#endif // TABLEVIEWMODEL_H


