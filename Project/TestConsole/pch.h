#ifndef _FRAMEWORK_TESTCONSOLE_PCH_H_
#define _FRAMEWORK_TESTCONSOLE_PCH_H_


#ifdef FRAMEWORK_TESTCONSOLE_DLL_IMPORT
#define FRAMEWORK_TESTCONSOLE_DLL_CLASS         __declspec(dllimport)
#define FRAMEWORK_TESTCONSOLE_DLL_FUNCTION      __declspec(dllimport)
#define FRAMEWORK_TESTCONSOLE_DLL_FUNCTION_C    extern "C" __declspec(dllimport)
#else
#define FRAMEWORK_TESTCONSOLE_DLL_CLASS         __declspec(dllexport)
#define FRAMEWORK_TESTCONSOLE_DLL_FUNCTION      __declspec(dllexport)
#define FRAMEWORK_TESTCONSOLE_DLL_FUNCTION_C    extern "C" __declspec(dllexport)
#endif

//ǥ�� ���
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


//�ܺ� ���
#include <Windows.h>



//���� ���
#include "../Core/Core.h"

//������Ʈ ���
#include "Namespace.h"
#include "Common.h"

#pragma comment(lib, "winmm.lib")

namespace Framework::TestConsole
{

}


#endif