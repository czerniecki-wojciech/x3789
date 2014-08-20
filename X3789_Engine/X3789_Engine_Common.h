
#ifdef XENGINE_EXPORT
#	define DLL_INTERFACE __declspec(dllexport)
#	define EXT extern "C"
#else
#	define DLL_INTERFACE __declspec(dllimport)
#	define EXT
#endif