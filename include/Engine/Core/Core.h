//
// Created by semyon on 03.12.2019.
//

#pragma once

#include <iostream>
#include <memory>




#ifdef _WIN32
#define FATON_WINDOWS_PLATFORM

#elif defined(__APPLE__) || defined(__MACH__)
#error "Apple Macintosh is not supported!"

#elif defined(__IOS__)
#error "IOS simulation not supported"

#elif defined(__ANDROID__)
#define FATON_ANDROID_PLATFORM
#error "Android is not currently supported"

#elif defined(__linux__)
#define FATON_LINUX_PLATFORM

#else
#error "Unknow platform is not support"

#endif

#define FATON_ERROR_01 std::cout << "ERROR_01: None API , or Engine does not see his, or API is currently not supported!" << std::endl
// Engine not use , or does not see API





namespace Engine
{

}


