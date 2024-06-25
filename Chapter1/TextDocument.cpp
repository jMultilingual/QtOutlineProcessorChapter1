#include "TextDocument.h"

TextDocument::TextDocument(QObject *parent)
    : QTextDocument{parent}
{
    setDocumentMargin(100);
    Common::setTextDocument(this);
}
