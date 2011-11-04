#ifndef H_XD_COMMON
#define H_XD_COMMON

#if defined(_WIN32) || defined(__CYGWIN__)
	#ifdef XD_EXPORT
		#ifdef XD_STATIC
			#define XD_API extern
		#else
			#define XD_API __declspec(dllexport)
			#define XD_API_TEMPLATE
		#endif
	#else
		#ifdef XD_STATIC
			#define XD_API
		#else
			#define XD_API __declspec(dllimport)
			#define XD_API_TEMPLATE extern
		#endif
	#endif
#else
	#ifdef XD_EXPORT
		#define XD_API extern
	#else
		#define XD_API
	#endif
#endif

#include <xd/common/types.h>
#include <xd/common/exception.h>
#include <xd/common/event_bus.h>

#endif
