#include <stdexcept>
#include <pqxx/pqxx>

#include "connectiondialog.h"
#include "./ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    ui->le_password_in->setEchoMode(QLineEdit::Password);
    db = std::make_unique<Database>();
}


ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}


void ConnectionDialog::on_clb_setup_connection_clicked()
{
    std::string options = 
            "host=" + ui->le_hostname_in->text().toStdString() + 
            " port=" + ui->le_port_in->text().toStdString() + 
            " dbname=" + ui->le_dbname_in->text().toStdString() + 
            " user=" + ui->le_username_in->text().toStdString() + 
            " password=" + ui->le_password_in->text().toStdString();
    try
    {
        db->setupConnection(options);
        ui->clb_unset_connection->setEnabled(true);
    }
    catch(const std::invalid_argument& inv_arg_ex)
    {
        // some_warning->show();
    }
    catch(...)
    {
        // some_error->show();
    }
}


void ConnectionDialog::on_clb_unset_connection_clicked()
{
    db->unsetConnection();
    ui->clb_unset_connection->setEnabled(false);
}

