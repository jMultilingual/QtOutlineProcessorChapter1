#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "Common.h"

class TextEdit : public QTextEdit
{
    Q_OBJECT
public:
    TextEdit();
    ~TextEdit();
    TextDocument* m_document = nullptr;
    QPushButton* m_lineEditToggleButton = nullptr;

    // QWidget interface
protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void inputMethodEvent(QInputMethodEvent *) override;
private slots:
    void lineEditFocusChange(bool checked);
};

#endif // TEXTEDIT_H
