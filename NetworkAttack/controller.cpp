#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    parser = new Parser(this);
}
