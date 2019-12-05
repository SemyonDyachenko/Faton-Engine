//
// Created by semyon on 03.12.2019.
//

#pragma once

#include <iostream>
#include <memory>


#ifdef _WIN32
#define ENGINE_PLATFORM_WINDOWS

#elif defined(__APPLE__) || defined(__MACH__)
#error "Apple Macintosh is not supported!"

#elif defined(__ANDROID__)
#error "Android is not supported!"

#elif defined(__linux__)
#define ENGINE_LINUX_PLATFORM

#else
#error "Unknow platform is not support"

#endif


namespace Engine
{

}


