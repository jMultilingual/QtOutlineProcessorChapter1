#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include "Common.h"

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();
    GraphicsView* m_graphicsView = nullptr;
    GraphicsScene* m_graphicsScene = nullptr;
    TextEdit* m_textEdit = nullptr;
    LineEdit* m_lineEdit = nullptr;
    ListView* m_listView = nullptr;
    QStateMachine* m_VStateMachine = nullptr;

    QPropertyAnimation* m_lineEditAnimationFromStart = nullptr;
    QPropertyAnimation* m_lineEditAnimationFromEnd = nullptr;
signals:
};

#endif // CENTRALWIDGET_H
