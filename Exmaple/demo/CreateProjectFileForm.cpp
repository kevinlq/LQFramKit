#include "CreateProjectFileForm.h"
#include "ui_CreateProjectFileForm.h"

#include <QFile>
#include <QFileInfo>
#include <QDir>

#include <QDateTime>

#define CUR_DATETIME    QDateTime::currentDateTime ().toString ("yyyy-MM-dd hh:mm:ss")

#include <QDebug>

CreateProjectFileForm::CreateProjectFileForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateProjectFileForm)
{
    ui->setupUi(this);

    this->initForm ();
}

CreateProjectFileForm::~CreateProjectFileForm()
{
    delete ui;
}

void CreateProjectFileForm::initForm()
{
    setWindowTitle ("子工程结构生成模板");
    ui->cbxSameProName->setChecked (true);
    ui->cbx_preview->setChecked (true);

    //默认生成全部文件
    ui->cbx_var->setChecked (true);
    ui->cbx_var_2->setChecked (true);
    ui->cbx_def->setChecked (true);
    ui->cbx_Inc->setChecked (true);
    ui->cbx_export->setChecked (true);
    ui->cbx_stdmain->setChecked (true);
    ui->cbx_struct->setChecked (true);
    ui->cbx_xxinc->setChecked (true);
    ui->cbx_xxincLib->setChecked (true);
    ui->cbx_xxLib->setChecked (true);

    m_strProName = "";
    m_strLibDefine = "";
}


bool CreateProjectFileForm::createFile(const QString &strName,const QString &strContext)
{
    QString strAppPath = QApplication::applicationDirPath ()+"/";
    QString strFilePath = strAppPath + strName;
    QString strPath = strFilePath.left (strFilePath.lastIndexOf ("/"));

    //若文件已经存在，则直接返回不进行任何操作
    if ( QFile::exists (strFilePath))
    {
        return true;
    }
    //若文件不存在，先检查文件所在的路径是否存在
    QDir dir(strPath);
    if ( !dir.exists (strPath))
    {
        //路径不存在，进行创建
        if ( !dir.mkpath (strPath))
        {
            qDebug()<<"create path error!";
            return false;
        }
    }

    //文件路径已经创建好了，接着进行创建文件
    QFile file(strFilePath);
    //这里以只写打开时，若文件不存则会自动创建
    if ( !file.open (QIODevice::WriteOnly))
    {
        return false;
    }
    //向文件写入内容
    file.write (strContext.toLatin1 ());

    file.close ();
    return true;
}

QString CreateProjectFileForm::getCommonHeadText(const QString &strName)
{
    QString strContext = QString("#ifndef %1_H\r\n").arg (strName.toUpper());
    strContext.append ( QString("#define %1_H\r\n").arg (strName.toUpper()));
    strContext.append ("\r\n");

    return strContext;
}

QString CreateProjectFileForm::getCommonEndText(const QString &strName)
{
    QString strContext = QString("#endif //%1_H\r\n").arg (strName.toUpper());

    return strContext;
}

QString CreateProjectFileForm::getCommonContext(const QString &strName)
{
    QString strContext = getCommonHeadText(strName) + getCommonEndText(strName) ;

    return strContext;
}

QString CreateProjectFileForm::getStdMainContext()
{
    QString strContext = "#ifndef STDMAIN_H\r\n \r\n";
    strContext.append ("#include \"Global/GlobalInclude.h\"\r\n\r\n");
    strContext.append ("#endif // STDMAIN_H\r\n");

    return strContext;
}

QString CreateProjectFileForm::getProFileContext(const QString &strProName)
{
    QString strContext = "#-------------------------------------------------\r\n#\r\n";
    strContext.append (QString("# Project created by QtCreator %1\r\n#\r\n").arg (CUR_DATETIME));
    strContext.append ("#-------------------------------------------------\r\n\r\n");
    strContext.append ("\r\n# add include pri file \r\n\r\n");
    strContext.append ("QT\t +=core\r\n\r\n");
    strContext.append ("TEMPLATE\t =lib\r\n");
    strContext.append ( QString("DEFINES\t +=%1_LIBRARY\r\n").arg (strProName.toUpper ()));
    strContext.append ( QString("TARGET\t =%1{FILE_POSTFIX}\r\n").arg (strProName));
    strContext.append ("\r\n\r\n");

    strContext.append ("SOURCES\t +=\\\r\n");
    strContext.append ("\tGlobal/GlobalVar.cpp \\");
    strContext.append ("\r\n\r\n");
    strContext.append ("HEADERS\t +=\\\r\n");
    strContext.append ("\tStdMain.h \\\r\n");
    strContext.append ("\tGlobal/GlobalVar.h \\\r\n");
    strContext.append ("\tGlobal/GlobalStruct.h \\\r\n");
    strContext.append ("\tGlobal/GlobalInclude.h \\\r\n");
    strContext.append ("\tGlobal/GlobalDef.h \\\r\n");

    strContext.append (QString("\t../%1/%2Inc.h \\\r\n").arg (strProName).arg (strProName));
    strContext.append (QString("\t../%1/%2IncLib.h \\\r\n").arg (strProName).arg (strProName));
    strContext.append (QString("\t%1_Export.h\r\n").arg (strProName));
    strContext.append ("\r\n");

    return strContext;
}

QString CreateProjectFileForm::getGlobalIncludeContext()
{
    QString strContext = getCommonHeadText ("GlobalInclude");
    strContext.append ("\r\n\r\n");
    strContext.append ("#include \"GlobalDef.h\"\r\n");
    strContext.append ("#include \"GlobalVar.h\"\r\n");
    strContext.append ("#include \"GlobalStruct.h\"\r\n");
    strContext.append ("\r\n");
    strContext.append ("\r\n");
    strContext.append ( QString("#include \"%1_Export.h\"").arg (m_strProName));
    strContext.append ("\r\n\r\n");
    strContext.append (getCommonEndText ("GlobalInclude"));

    return strContext;
}

QString CreateProjectFileForm::getExportContext()
{
    QString strContext = getCommonHeadText ( QString("%1_Export").arg (m_strProName));
    strContext.append ("\r\n");
    strContext.append ("#if defined(MIV_XXX_LIBRARY)\r\n");
    strContext.append ( QString("#  define %1_Export XXX_DECL_EXPORT\r\n").arg (m_strProName));
    strContext.append ("#else\r\n");
    strContext.append (QString("#  define %1_Export XXX_DECL_IMPORT\r\n").arg (m_strProName));
    strContext.append ("#endif\r\n\r\n");

    strContext.append (getCommonEndText(QString("%1_Export").arg (m_strProName)));

    return strContext;
}

QString CreateProjectFileForm::getIncContext()
{
    QString strContext = getCommonHeadText ( QString("%1_inc").arg (m_strProName));
    strContext.append ("\r\n");
    strContext.append ( QString("#include \"%1_Export.h\"\r\n").arg (m_strProName));
    strContext.append ("\r\n");
    strContext.append (getCommonEndText(QString("%1_Inc").arg (m_strProName)));

    return strContext;
}

QString CreateProjectFileForm::getIncLibContext()
{
    QString strContext = getCommonHeadText ( QString("%1_incLib").arg (m_strProName));
    strContext.append ("\r\n");
    strContext.append ( QString("#include \"%1_Inc.h\"\r\n").arg (m_strProName));
    strContext.append ( QString("#include \"%1_Lib.h\"\r\n").arg (m_strProName));
    strContext.append ("\r\n");
    strContext.append (getCommonEndText(QString("%1_IncLib").arg (m_strProName)));

    return strContext;
}

void CreateProjectFileForm::on_pbnCreate_clicked()
{
    QString strProName = ui->let_proName->text ().trimmed ();
    QString strFolderName = ui->let_folderName->text ().trimmed ();
    bool bResult = false;
    m_strProName = strProName;

    if ( strProName.isEmpty () || strFolderName.isEmpty ())
    {
        qDebug()<<"file name is emprt";
        return;
    }

    m_FileMap.insert ( QString("%1/StdMain.h").arg (strFolderName),getStdMainContext());
    m_FileMap.insert (QString("%1/%2.pro").arg (strFolderName).arg (strProName),getProFileContext(strProName));
    m_FileMap.insert (QString("%1/Global/GlobalDef.h").arg (strFolderName),getCommonContext ("GlobalDef"));
    m_FileMap.insert (QString("%1/Global/GlobalStruct.h").arg (strFolderName),getCommonContext ("GlobalStruct"));
    m_FileMap.insert (QString("%1/Global/GlobalVar.h").arg (strFolderName),getCommonContext ("GlobalVar"));
    m_FileMap.insert (QString("%1/Global/GlobalVar.cpp").arg (strFolderName),"");
    m_FileMap.insert (QString("%1/Global/GlobalInclude.h").arg (strFolderName),getGlobalIncludeContext ());

    //include 文件
    m_FileMap.insert (QString("%1/%2/%3_Export.h").arg (strFolderName).arg (strFolderName).arg (strProName),
                      getExportContext());
    m_FileMap.insert (QString("%1/%2/%3_Inc.h").arg (strFolderName).arg (strFolderName).arg (strProName),
                      getIncContext());
    m_FileMap.insert (QString("%1/%2/%3_IncLib.h").arg (strFolderName).arg (strFolderName).arg (strProName),
                      getIncLibContext ());
    m_FileMap.insert (QString("%1/%2/%3_Lib.h").arg (strFolderName).arg (strFolderName).arg (strProName),
                      getCommonContext( QString("%1Lib").arg (strProName)));

    //创建文件以及写入内容
    for (auto it = m_FileMap.begin (); it != m_FileMap.end (); it++)
    {
        bResult = createFile(it.key (),it.value ());
        if ( !bResult )
        {
            qDebug()<<"==============create file error!===============";
            qDebug()<<"==:"<<it.key ()<<" "<<it.value ();
        }
    }
}
