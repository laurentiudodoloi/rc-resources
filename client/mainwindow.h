#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool checkFileSelected();
    Ui::MainWindow *ui;

    void setView(QString name);
    void setFiles();

private slots:

    void on_downloadBtn_pressed();
    void onAccept(int x);
    void onRefuse();

    void on_exitBtn_clicked();

    void on_filelist_currentTextChanged(const QString &currentText);

    void on_openBtn_clicked();

    void on_deleteBtn_clicked();

    void on_myDriveBtn_clicked();

    void on_sharedBtn_clicked();

    void on_retryBtn_clicked();

    void on_downloadBtn_clicked();

private:
    //
};

#endif // MAINWINDOW_H
