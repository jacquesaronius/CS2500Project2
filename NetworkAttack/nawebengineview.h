#ifndef NAWEBENGINEVIEW_H
#define NAWEBENGINEVIEW_H

#include <QWebEngineView>

class NAWebEngineView : public QWebEngineView
{
public:
    NAWebEngineView(QWebEnginePage *, QObject * = Q_NULLPTR);
};

#endif // NAWEBENGINEVIEW_H
