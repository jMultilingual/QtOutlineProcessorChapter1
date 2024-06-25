#include "TextEdit.h"
#include "TextDocument.h"
#include "LineEdit.h"

TextEdit::TextEdit()
{
    resize(Common::A4);
    Common::setTextEdit(this);
    m_document = new TextDocument(this);
    setDocument(m_document);
    m_lineEditToggleButton = new QPushButton();
    m_lineEditToggleButton->setCheckable(true);
    connect(m_lineEditToggleButton,
            &QPushButton::clicked,
            this,
            &TextEdit::lineEditFocusChange);
}

TextEdit::~TextEdit()
{
    delete m_lineEditToggleButton;
}


void TextEdit::mouseMoveEvent(QMouseEvent *event)
{
}

void TextEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F
        && event->modifiers()
               == Qt::ControlModifier)
    {
        emit m_lineEditToggleButton->clicked();
        return;
    }
    QTextEdit::keyPressEvent(event);
}

void TextEdit::keyReleaseEvent(QKeyEvent *event)
{
    QTextEdit::keyReleaseEvent(event);
}

void TextEdit::inputMethodEvent(QInputMethodEvent *event)
{
    QTextEdit::inputMethodEvent(event);
}

void TextEdit::lineEditFocusChange(bool checked)
{
    if (!checked)
    {
        Common::lineEdit()->setFocus();
    }
    else
    {
        Common::lineEdit()->
            setFocusPolicy(Qt::NoFocus);
    }
}
