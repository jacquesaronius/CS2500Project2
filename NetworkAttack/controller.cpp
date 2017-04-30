#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    parser = new Parser(this);
}


int Controller::test_parser()
{

    return 0;
}
