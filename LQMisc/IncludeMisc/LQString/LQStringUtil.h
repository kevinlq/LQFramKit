#ifndef LQSTRINGUTIL_H
#define LQSTRINGUTIL_H

#include <QStringList>
#include <QVariantMap>

class LQString_Export LQStringUtil
{
public:
    explicit LQStringUtil();
    ~LQStringUtil();

public:
    static  QString variantMapToJsonString(const QVariantMap & map);
    static  QVariantMap variantMapFromJsonString(const QString & json);
    static  QVariant variantFromJsonString(const QString & json);
    static  QString variantToJsonString(const QVariant & json);
};

#endif // LQSTRINGUTIL_H
