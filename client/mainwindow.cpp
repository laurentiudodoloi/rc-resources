#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QTextStream>
#include "ui_mydialog.h"
#include "global.h"
#include "colab-api.h"
#include "request.h"
#include "ui_texteditor.h"
#include "texteditor.h"
#include "file-manager.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setView("home");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFiles() {
    ui->filelist->clear();

    for (auto it = Global::fileList.begin(); it != Global::fileList.end(); it++) {
        qDebug(it->c_str());
        ui->filelist->addItem(it->c_str());
    }
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
    Global::selectFile(File(currentText.toStdString().c_str()));
}

void MainWindow::on_openBtn_clicked()
{
    if (!checkFileSelected()) {
        return;
    }

    ColabApi *api = ColabApi::getInstance();

    std::string content = api->getFileContent(Global::currentFile.text.toStdString());
    Global::tempText = content;

    TextEditor textEditor;

    textEditor.setFile(Global::currentFile.text);

    textEditor.setModal(true);
    textEditor.exec();
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
}

void MainWindow::setView(QString name) {
    ColabApi *api = ColabApi::getInstance();

    ui->errorLabel->setVisible(false);
    ui->retryBtn->setVisible(false);

    if (!api->connected) {
        ui->errorLabel->setVisible(true);
        ui->retryBtn->setVisible(true);
    }

    if (name.contains("home")) {
        Global::fileList = api->getFileList();

        ui->filesControls->setVisible(true);
    } else if (name.contains("downloads")) {
        Global::fileList = FileManager::getFileList((QDir::homePath().toStdString() + "/Downloads/colab-local").c_str());

        ui->filesControls->setVisible(false);
    }

    this->setFiles();
}

void MainWindow::on_myDriveBtn_clicked()
{
    setView("home");
}

void MainWindow::on_sharedBtn_clicked()
{
    setView("downloads");
}

void MainWindow::on_retryBtn_clicked()
{
    this->setView("home");
}

void MainWindow::on_downloadBtn_clicked()
{
    if (!checkFileSelected()) {
        return;
    }

    ColabApi *api = ColabApi::getInstance();

    int success = api->downloadFile(Global::currentFile.text.toStdString(), QDir::homePath().toStdString() + "/Downloads/colab-local");

    qDebug(QString::number(success).toStdString().c_str());
}
