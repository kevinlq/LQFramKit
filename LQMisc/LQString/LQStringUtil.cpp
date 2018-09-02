#include "StdMain.h"

#include "LQStringUtil.h"

#include <QJsonDocument>

LQStringUtil::LQStringUtil()
{

}

LQStringUtil::~LQStringUtil()
{
}

QString LQStringUtil::variantMapToJsonString(const QVariantMap &map)
{
    QJsonDocument doc = QJsonDocument::fromVariant(QVariant(map));
    return doc.toJson(QJsonDocument::Indented);
}

QVariantMap LQStringUtil::variantMapFromJsonString(const QString &json)
{
    QByteArray ba = json.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    return doc.toVariant().toMap();
}

QVariant LQStringUtil::variantFromJsonString(const QString &json)
{
    QByteArray ba = json.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    return doc.toVariant();
}

QString LQStringUtil::variantToJsonString(const QVariant &json)
{
    QJsonDocument doc = QJsonDocument::fromVariant(json);
    return doc.toJson(QJsonDocument::Indented);
}
