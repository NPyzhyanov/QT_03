#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ConnectionDialog;
}
QT_END_NAMESPACE

class ConnectionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();
    
private slots:
    void on_clb_setup_connection_clicked();
    void on_clb_unset_connection_clicked();
    
private:
    Ui::ConnectionDialog *ui;
    std::unique_ptr<Database> db;
};

#endif // CONNECTIONDIALOG_H
