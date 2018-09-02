#ifndef LQSTRING_EXPORT_H
#define LQSTRING_EXPORT_H

#include "GlobalInc.h"

#if defined(LQSTRING_LIBRARY)
#  define LQString_Export LQ_DECL_EXPORT
#else
#  define LQString_Export LQ_DECL_IMPORT
#endif

#endif //LQSTRING_EXPORT_H
