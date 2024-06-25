#ifndef TEXTDOCUMENT_H
#define TEXTDOCUMENT_H

#include "Common.h"

class TextDocument : public QTextDocument
{
    Q_OBJECT
public:
    explicit TextDocument(QObject *parent = nullptr);
};

#endif // TEXTDOCUMENT_H
