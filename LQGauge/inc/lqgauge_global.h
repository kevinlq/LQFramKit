#ifndef LQGAUGE_GLOBAL_H
#define LQGAUGE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LQGAUGE_LIBRARY)
#  define LQGAUGESHARED_EXPORT Q_DECL_EXPORT
#else
#  define LQGAUGESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LQGAUGE_GLOBAL_H
