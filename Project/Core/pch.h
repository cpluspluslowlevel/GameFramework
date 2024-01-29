#ifndef _FRAMEWORK_CORE_PCH_H_
#define _FRAMEWORK_CORE_PCH_H_


#ifdef FRAMEWORK_CORE_DLL_IMPORT
#define FRAMEWORK_CORE_DLL_CLASS         __declspec(dllimport)
#define FRAMEWORK_CORE_DLL_FUNCTION      __declspec(dllimport)
#define FRAMEWORK_CORE_DLL_FUNCTION_C    extern "C" __declspec(dllimport)
#else
#define FRAMEWORK_CORE_DLL_CLASS         __declspec(dllexport)
#define FRAMEWORK_CORE_DLL_FUNCTION      __declspec(dllexport)
#define FRAMEWORK_CORE_DLL_FUNCTION_C    extern "C" __declspec(dllexport)
#endif

//표준 헤더
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <functional>
#include <assert.h>
#include <thread>
#include <mutex>


//외부 헤더
#include <Windows.h>


//프로젝트 헤더
#include "Namespace.h"
#include "Common.h"

#pragma comment(lib, "winmm.lib")

namespace Framework::Core
{

}


#endif