/********************************************************************************
** Form generated from reading UI file 'texteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TextEditor
{
public:
    QPushButton *btnSend;
    QPlainTextEdit *editArea;

    void setupUi(QDialog *TextEditor)
    {
        if (TextEditor->objectName().isEmpty())
            TextEditor->setObjectName(QStringLiteral("TextEditor"));
        TextEditor->resize(657, 484);
        btnSend = new QPushButton(TextEditor);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(520, 430, 89, 25));
        editArea = new QPlainTextEdit(TextEditor);
        editArea->setObjectName(QStringLiteral("editArea"));
        editArea->setGeometry(QRect(20, 20, 621, 391));
        editArea->setStyleSheet(QLatin1String("padding: 12px 16px;\n"
"border-radius: 6px;\n"
"background: white;"));
        editArea->setCursorWidth(2);

        retranslateUi(TextEditor);

        QMetaObject::connectSlotsByName(TextEditor);
    } // setupUi

    void retranslateUi(QDialog *TextEditor)
    {
        TextEditor->setWindowTitle(QApplication::translate("TextEditor", "Dialog", Q_NULLPTR));
        btnSend->setText(QApplication::translate("TextEditor", "Send", Q_NULLPTR));
        editArea->setPlainText(QApplication::translate("TextEditor", "Hello from here.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TextEditor: public Ui_TextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H
