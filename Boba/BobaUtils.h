#pragma once
#ifdef BOBA_WINDOWS
#ifdef BOBA_LIB
		#define BOBA_API __declspec(dllexport)
#else
		#define BOBA_API __declspec(dllimport)
#endif
#else
#define BOBA_API
#endif

#ifdef BOBA_DEBUG
	#define BOBA_LOG(x) std::cout<<x<<std::endl;
#else
	#define BOBA_LOG(x)
#endif // BOBA_DEBUG
