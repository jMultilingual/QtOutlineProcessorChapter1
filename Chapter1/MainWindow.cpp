#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "CentralWidget.h"
#include "ListView.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_cw = new CentralWidget();
    setCentralWidget(m_cw);
    Common::setMainWindow(this);

    ListView* l = new ListView();
    QDockWidget* d = new QDockWidget();
    d->setWidget(l);
    addDockWidget(Qt::LeftDockWidgetArea,
                  d);
}

MainWindow::~MainWindow()
{
    delete ui;
}
