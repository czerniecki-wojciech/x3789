
#include "LibraryLoader.h"

#ifdef __linux
#	include <X3789_Engine/X3789_Engine.h>
#else
#	include <Windows.h>
#endif

void LibraryLoader::loadAll()
{
#ifdef __linux
	X3789_Engine_start();
#else
	LoadLibrary("X3789_Engine");
#endif
}

LibraryLoader::LibraryLoader()
{
}


LibraryLoader::~LibraryLoader()
{
}
