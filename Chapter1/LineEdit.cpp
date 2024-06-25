#include "LineEdit.h"
#include "TextEdit.h"
LineEdit::LineEdit()
{
    setFixedHeight(
        Common::StartValue
        );
    setFocusPolicy(Qt::NoFocus);
    Common::setLineEdit(this);
}

void LineEdit::setFixedHeight(int fixedHeight)
{
    QLineEdit::setFixedHeight(fixedHeight);
    m_fixedHeight = fixedHeight;
}

int LineEdit::getFixedHeight()
{
    return m_fixedHeight;
}


void LineEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F &&
        event->modifiers()
        == Qt::ControlModifier)
    {
        emit Common::textEdit()->
            m_lineEditToggleButton->
            clicked(true);
        Common::textEdit()->setFocus();
        return;
    }
    QLineEdit::keyPressEvent(event);
}


void LineEdit::focusOutEvent(QFocusEvent *event)
{
    emit Common::textEdit()->
        m_lineEditToggleButton->
        clicked(false);
    Common::textEdit()->setFocus();
    QLineEdit::focusOutEvent(event);
}
