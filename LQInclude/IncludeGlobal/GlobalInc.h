#ifndef GLOBAL_INC_H
#define GLOBAL_INC_H

#if  defined (STATIC_LIBRARY) && defined (Q_OS_WIN)
#define LQ_DECL_EXPORT
#define LQ_DECL_IMPORT
#else
#include <QtCore/qglobal.h>

#define LQ_DECL_EXPORT  Q_DECL_EXPORT
#define LQ_DECL_IMPORT  Q_DECL_IMPORT

#endif

#endif //GLOBAL_INC_H
