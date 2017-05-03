#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>

class Location : public QObject
{
    Q_OBJECT
    Q_PROPERTY(short x1 READ x1 WRITE setX1)
    Q_PROPERTY(short y1 READ y1 WRITE setY1)
    Q_PROPERTY(short x2 READ x2 WRITE setX2)
    Q_PROPERTY(short y2 READ y2 WRITE setY2)
public:
    explicit Location(QObject *parent = 0);

signals:

public slots:
};

#endif // LOCATION_H
