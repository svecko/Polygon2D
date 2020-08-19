#pragma once

#ifdef POLYGON2D_PLATFORM_WINDOWS
	#ifdef POLYGON2D_BUILD_DLL
		#define POLYGON2D_API __declspec(dllexport)
	#else
		#define POLYGON2D_API __declspec(dllimport)
	#endif // POLYGON2D_BUILD_DLL
#else
	#error Polygon2D is only supported on Windows.
#endif // POLYGON2D_PLATFORM_WINDOWS
