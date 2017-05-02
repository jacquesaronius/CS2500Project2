#include "nawebenginepage.h"

NAWebEnginePage::NAWebEnginePage(QObject *parent) : QWebEnginePage(parent)
{
}


QString NAWebEnginePage::userAgentForUrl(const QUrl &url) const
{
    return "Chrome/1.0";
}

