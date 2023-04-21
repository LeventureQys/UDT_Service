#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(UDT_RECIVER_LIB)
#  define UDT_RECIVER_EXPORT Q_DECL_EXPORT
# else
#  define UDT_RECIVER_EXPORT Q_DECL_IMPORT
# endif
#else
# define UDT_RECIVER_EXPORT
#endif
