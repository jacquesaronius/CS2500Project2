#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "parser.h"

class Controller : public QObject
{
    Q_OBJECT

    Parser * parser;
public:
    explicit Controller(QObject *parent = 0);

signals:

public slots:
};

#endif // CONTROLLER_H
