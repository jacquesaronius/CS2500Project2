#include "nawebengineview.h"

NAWebEngineView::NAWebEngineView(QWebEnginePage * page, QObject * parent)
    : QWebEngineView(parent)
{
    this->setPage(page);
}
