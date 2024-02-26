#ifndef _FRAMEWORK_GRAPHICSDX12_PCH_H_
#define _FRAMEWORK_GRAPHICSDX12_PCH_H_


#ifdef FRAMEWORK_GRAPHICSDX12_DLL_IMPORT
#define FRAMEWORK_GRAPHICSDX12_DLL_CLASS         __declspec(dllimport)
#define FRAMEWORK_GRAPHICSDX12_DLL_FUNCTION      __declspec(dllimport)
#define FRAMEWORK_GRAPHICSDX12_DLL_FUNCTION_C    extern "C" __declspec(dllimport)
#else
#define FRAMEWORK_GRAPHICSDX12_DLL_CLASS         __declspec(dllexport)
#define FRAMEWORK_GRAPHICSDX12_DLL_FUNCTION      __declspec(dllexport)
#define FRAMEWORK_GRAPHICSDX12_DLL_FUNCTION_C    extern "C" __declspec(dllexport)
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
#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>

//내부 헤더
#include "../Core/Core.h"

//프로젝트 헤더
#include "Namespace.h"
#include "Common.h"

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

namespace Framework::GraphicsDX12
{

}


#endif