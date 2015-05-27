
#include "LibraryLoader.h"

#ifndef __linux
#	include <Windows.h>
#endif

#include <X3789_Engine/X3789_Engine.h>

void LibraryLoader::loadAll()
{
#ifndef __linux
    //LoadLibrary("X3789_Engine");
#endif
	X3789_Engine_start();
}

LibraryLoader::LibraryLoader()
{
}


LibraryLoader::~LibraryLoader()
{
}
