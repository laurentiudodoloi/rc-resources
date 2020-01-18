#include "texteditor.h"
#include "ui_texteditor.h"
#include "qdebug.h"
#include "global.h"
#include "request.h"
#include "colab-api.h"

TextEditor::TextEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);

    ui->editArea->setCursorWidth(2);
    ui->editArea->setStyleSheet("color: #FF0000; background: red !important;");
    ui->editArea->setStyleSheet("QPlainTextEdit{color: #333; background-color: #ffffff; selection-background-color: blue; selection-color: #ffffff;}");

    QTextCharFormat fmt;
    fmt.setForeground(QBrush(QColor(128, 125, 12)));

    ui->editArea->mergeCurrentCharFormat(fmt);

    QTextCursor cursor = ui->editArea->textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 8);
    ui->editArea->setTextCursor(cursor);

    ui->editArea->setPlainText(Global::tempText.c_str());
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::setFile(QString name) {
    this->setWindowTitle(name);
}

void TextEditor::on_editArea_cursorPositionChanged()
{
    //
}

void TextEditor::on_editArea_textChanged()
{
    if (!this->init) {
        this->init = true;
        return ;
    }
}

void TextEditor::on_editArea_blockCountChanged(int newBlockCount)
{
    //
}

void TextEditor::on_btnSend_clicked()
{
    qDebug("Send button clicked.");

    int pos = (int)ui->editArea->textCursor().position();

//    std::string str = QString::number(pos).toStdString() + ":" + QString(ui->editArea->toPlainText().toStdString().at(pos)).toStdString().c_str();
    std::string str = ui->editArea->toPlainText().toStdString();

    ColabApi *api = ColabApi::getInstance();
    api->init();

    Request request;

    std::string content = request.post("write/" + Global::currentFile.text.toStdString(), str, api->client->clientSocket);
}
