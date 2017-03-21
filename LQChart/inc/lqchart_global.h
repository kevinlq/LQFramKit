#ifndef LQCHART_GLOBAL_H
#define LQCHART_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LQCHART_LIBRARY)
#  define LQCHARTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LQCHARTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LQCHART_GLOBAL_H
