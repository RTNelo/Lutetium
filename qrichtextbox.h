//Î´Íê³É
#ifndef QRICHTEXTBOX_H
#define QRICHTEXTBOX_H

#include <QTextEdit>
#include <QTextDocument>
#include "qrichconfigure.h"

class QRichTextBox : public QTextEdit
{
    Q_OBJECT
private:
    QTextDocument *textDoc;
    QRichConfigureList *conf;
public:
    QRichTextBox();
};

#endif // QRICHTEXTBOX_H
