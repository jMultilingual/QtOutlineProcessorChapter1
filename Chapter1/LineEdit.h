#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "Common.h"

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    LineEdit();
    Q_PROPERTY(int m_fixedHeight
               WRITE setFixedHeight
               READ getFixedHeight
               NOTIFY fixedHeightChanged)
    int m_fixedHeight;
    void setFixedHeight(int fixedHeight);
    int getFixedHeight();

signals:
    void fixedHeightChanged();

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void focusOutEvent(QFocusEvent *event) override;
};

#endif // LINEEDIT_H
