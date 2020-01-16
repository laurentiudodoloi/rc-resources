#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QTextStream>
#include "qdebug.h"
#include "ui_mydialog.h"
#include "global.h"

#include "colab-api.h"
#include "request.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ColabApi *api = ColabApi::getInstance();

    Request request;

    json j = json::parse(request.get("/", api->client->clientSocket));

    qDebug("here");
    auto& files = j["files"];

    std::list<std::string> fileList;
    for (json::iterator it = files.begin(); it != files.end(); it++) {
        ui->filelist->addItem(QString((*it).dump().c_str()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_downloadBtn_pressed()
{
    if (!checkFileSelected()) {
        return;
    }
}

void MainWindow::onAccept(int x)
{
    qDebug("Accept.");
}

void MainWindow::onRefuse()
{
    qDebug("Refuse.");
}

void MainWindow::on_exitBtn_clicked()
{
    QDialog qDialog(this);

    Ui::MyDialog myDialog;

    myDialog.setupUi(&qDialog);
    myDialog.label->setText("Are you sure you want to quit the application ?");

    int result = qDialog.exec();

    if (result == QDialog::Accepted) {
        QApplication::quit();
    }
}

void MainWindow::on_filelist_currentTextChanged(const QString &currentText)
{
    qDebug((const char *) currentText.toStdString().c_str());

    Global::selectFile(File(currentText.toStdString().c_str()));
}

void MainWindow::on_openBtn_clicked()
{
    if (!checkFileSelected()) {
        return;
    }

    qDebug("Open file:");
    qDebug(Global::currentFile.text.toStdString().c_str());
}

bool MainWindow::checkFileSelected() {
    if (!Global::isFileSelected()) {
        QDialog qDialog(this);

        qDialog.setWindowTitle("Collaborative Notepad - Dialog");

        Ui::MyDialog myDialog;

        myDialog.setupUi(&qDialog);
        myDialog.buttonBox->setVisible(false);
        myDialog.label->setText("No file selected. Please select the file you want to download.");

        return false;
    }

    return true;
}

void MainWindow::on_deleteBtn_clicked()
{
    if (!checkFileSelected()) {
        return;
    }

    qDebug("Delete file:");
    qDebug(Global::currentFile.text.toStdString().c_str());
}
