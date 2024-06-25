#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Common.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ListView* m_listView = nullptr;
private:
    Ui::MainWindow *ui;
    CentralWidget* m_cw;
};
#endif // MAINWINDOW_H
