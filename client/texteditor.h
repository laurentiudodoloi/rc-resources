#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QDialog>

namespace Ui {
class TextEditor;
}

class TextEditor : public QDialog
{
    Q_OBJECT

public:
    bool init = false;

    explicit TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

    void setFile(QString name);

private slots:
    void on_editArea_cursorPositionChanged();

    void on_editArea_textChanged();

    void on_editArea_blockCountChanged(int newBlockCount);

    void on_btnSend_clicked();

private:
    Ui::TextEditor *ui;
};

#endif // TEXTEDITOR_H
