#ifndef LQMETER_GLOBAL_H
#define LQMETER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LQMETER_LIBRARY)
#  define LQMETERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LQMETERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LQMETER_GLOBAL_H
