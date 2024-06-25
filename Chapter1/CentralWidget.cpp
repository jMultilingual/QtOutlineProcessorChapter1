#include "CentralWidget.h"
#include "GraphicsView.h"
#include "GraphicsScene.h"
#include "TextEdit.h"
#include "ListView.h"
#include "LineEdit.h"

CentralWidget::CentralWidget(QWidget *parent)
    : QWidget{parent}
{
    m_graphicsView = new GraphicsView();
    m_graphicsScene = new GraphicsScene();
    m_textEdit = new TextEdit();
    m_graphicsScene->addWidget(m_textEdit);
    m_graphicsView->setScene(m_graphicsScene);

    m_listView = new ListView();
    m_lineEdit = new LineEdit();

    QVBoxLayout* v = new QVBoxLayout();
    v->addWidget(m_lineEdit);
    v->addWidget(m_graphicsView);

    setLayout(v);

    m_VStateMachine = new QStateMachine(this);
    QState* startState = new QState(
        m_VStateMachine
        );
    startState->assignProperty(
        m_lineEdit,
        Common::PropertyName,
        Common::StartValue
        );
    QState* endState = new QState(
        m_VStateMachine
        );
    endState->assignProperty(
        m_lineEdit,
        Common::PropertyName,
        Common::EndValue
        );
    m_VStateMachine->setInitialState(
        startState
        );
    QSignalTransition* startSig = startState->
        addTransition(
        m_textEdit->m_lineEditToggleButton,
        &QPushButton::clicked,
        endState
        );
    QSignalTransition* endSig = endState->
        addTransition(
        m_textEdit->m_lineEditToggleButton,
        &QPushButton::clicked,
        startState);
    m_lineEditAnimationFromStart =
        new QPropertyAnimation(this);
    m_lineEditAnimationFromStart->
        setTargetObject(
        m_lineEdit
        );
    m_lineEditAnimationFromStart->
        setStartValue(
        Common::StartValue
        );
    m_lineEditAnimationFromStart->
        setEndValue(
        Common::EndValue
        );
    m_lineEditAnimationFromStart->
        setDuration(
        Common::Duration
        );
    m_lineEditAnimationFromStart->
        setPropertyName(
        QByteArray(Common::PropertyName)
        );
    startSig->addAnimation
        (
        m_lineEditAnimationFromStart
        );

    m_lineEditAnimationFromEnd =
        new QPropertyAnimation(this);
    m_lineEditAnimationFromEnd->
        setTargetObject(
        m_lineEdit
        );
    m_lineEditAnimationFromEnd->
        setStartValue(
        Common::StartValue
        );
    m_lineEditAnimationFromEnd->
        setEndValue(
            Common::EndValue
            );
    m_lineEditAnimationFromEnd->
        setDuration(
            Common::Duration
            );
    m_lineEditAnimationFromEnd->
        setPropertyName(
            QByteArray(Common::PropertyName)
            );
    m_lineEditAnimationFromEnd->
        setDirection(
        QPropertyAnimation::Backward
        );
    endSig->addAnimation
        (
            m_lineEditAnimationFromEnd
            );
    m_VStateMachine->start();

    Common::textEdit()->setFocus();
}

CentralWidget::~CentralWidget()
{

}
