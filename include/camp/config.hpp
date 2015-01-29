#pragma once

// We define the CAMP_API macro according to the
// current operating system and build mode
#if defined(_WIN32) || defined(__WIN32__)
	#if !defined(CAMP_STATIC)
		#if defined(CAMP_EXPORTS)
			#define CAMP_API __declspec(dllexport)
		#else
			#define CAMP_API __declspec(dllimport)
		#endif
	#else
		#define CAMP_API
	#endif
#else
	#define CAMP_API
#endif

// We disable some annoying warnings of VC++
//#if defined(_MSC_VER)
//	#pragma warning(disable: 4275) // non dll-interface class 'X' used as base for dll-interface class 'Y'
//	#pragma warning(disable: 4251) // class 'X' needs to have dll-interface to be used by clients of class 'Y'
//#endif

