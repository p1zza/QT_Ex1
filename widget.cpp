#include "widget.h"
#include "ui_widget.h"
//#include <QMessageBox>
#include <QFileDialog>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableView->setModel(&boardViewModel);
    QHeaderView* headers = ui->tableView->horizontalHeader();
    headers->setMinimumSectionSize(150);
    headers->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_Delete_clicked()
{
    int rowCount = ui->tableView->selectionModel()->selectedRows().count();
    if (rowCount > 0)
    {
        int ret = QMessageBox::question(this, tr("Delete?"),tr("Do you want to delete person?"),QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel);
        if (ret == QMessageBox::Ok)
        {
          QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
          QList<int> rows;
          for (int i = 0; i < selectedRows.size(); i++)
          {
              rows.append(selectedRows[i].row());
          }
          boardViewModel.del(rows);
        }
    }
    else
    {
        QMessageBox::information(this, tr("Error"),tr("You don`t choose any person"),QMessageBox::Ok);
    }
}

void Widget::on_pushButton_Add_clicked()
{
    boardViewModel.addPerson();
}

void Widget::on_pushButton_Save_clicked()
{
    QFileDialog::Options options = QFileDialog::Options(QFileDialog::DontUseNativeDialog);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save"), "", tr("Json (*.json)"), nullptr, options);
    if (fileName != "")
    {
        if(!fileName.contains(".json"))
        {
          fileName += ".json";
        }
        boardViewModel.saveToJson(fileName);
    }
}

void Widget::on_pushButton_Load_clicked()
{
    int ret = QMessageBox::question(this, tr("Do you want to save file?"),tr("Save data before exit?"),
                                    QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,QMessageBox::Save);

    switch(ret)
    {
        case QMessageBox::Save :  on_pushButton_Save_clicked();
        break;

        case QMessageBox::Cancel : return;
        break;
    }



    QFileDialog::Options options = QFileDialog::Options(QFileDialog::DontUseNativeDialog);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Json (*.json)"), nullptr, options);
    if (fileName != "")
    {
        boardViewModel.loadFromJson(fileName);
    }
}
