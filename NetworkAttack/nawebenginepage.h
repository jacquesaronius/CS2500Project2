#ifndef NAWEBENGINEPAGE_H
#define NAWEBENGINEPAGE_H

#include <QWebEnginePage>
class NAWebEnginePage : public QWebEnginePage
{
    virtual QString userAgentForUrl(const QUrl & url) const;

public:
    NAWebEnginePage(QObject * parent = Q_NULLPTR);
};

#endif // NAWEBPAGE_H
