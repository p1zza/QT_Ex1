#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "boardviewmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_Delete_clicked();

    void on_pushButton_Add_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_Load_clicked();

private:
    Ui::Widget *ui;
    BoardViewModel boardViewModel;
};
#endif // WIDGET_H
