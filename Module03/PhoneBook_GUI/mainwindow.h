#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddPushButton_clicked();

    void on_SearchPushButton_clicked();

    void on_RemovePushButton_clicked();

    void on_AddMainPushButton_clicked();

    void on_SearchMainPushButton_clicked();

    void on_RemoveMainPushButton_clicked();

    void on_AddSubmitPushButton_clicked();

    void on_SearchPushButton_2_clicked();

    void on_RemovePushButton_2_clicked();

    void on_RemoveEnterPushButton_clicked();

    void on_ListPushButton_clicked();

    void on_SaveListPushButton_clicked();

    void on_ReloadListPushButton_clicked();

    void on_ListMainPushButton_clicked();

    void on_RemoveMainPushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
