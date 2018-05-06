#ifndef CREATEPROJECTFILEFORM_H
#define CREATEPROJECTFILEFORM_H

#include <QWidget>
#include <QMap>

namespace Ui {
class CreateProjectFileForm;
}

class CreateProjectFileForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateProjectFileForm(QWidget *parent = 0);
    ~CreateProjectFileForm();

private:
    void initForm();

    bool createFile(const QString &strName, const QString &strContext);

    QString getCommonHeadText(const QString &strName);

    QString getCommonEndText(const QString &strName);

    QString getCommonContext(const QString &strName);

    QString getStdMainContext();

    QString getProFileContext(const QString &strProName);

    QString getGlobalIncludeContext();

    QString getExportContext();
    QString getIncContext();
    QString getIncLibContext();

private slots:
    void on_pbnCreate_clicked();

private:
    Ui::CreateProjectFileForm *ui;

    QMap<QString,QString>m_FileMap;
    QString m_strProName;
    QString m_strLibDefine;
};

#endif // CREATEPROJECTFILEFORM_H
