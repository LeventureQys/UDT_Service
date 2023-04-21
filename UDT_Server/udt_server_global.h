#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(UDT_SERVER_LIB)
#  define UDT_SERVER_EXPORT Q_DECL_EXPORT
# else
#  define UDT_SERVER_EXPORT Q_DECL_IMPORT
# endif
#else
# define UDT_SERVER_EXPORT
#endif
