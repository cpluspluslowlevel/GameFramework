//외부에서 모듈을 사용할 때 불어와야 하는 헤더입니다.
//프로젝트 내부에서는 사용해선 안됩니다.



#ifndef _FRAMEWORK_GRAPHICSDX12_GRAPHICSDX12_H_
#define _FRAMEWORK_GRAPHICSDX12_GRAPHICSDX12_H_

#define FRAMEWORK_GRAPHICSDX12_DLL_IMPORT
#include "pch.h"

#ifdef _WIN64
    #ifdef _DEBUG
        #pragma comment(lib, "GraphicsDX12_x64_Debug.lib")
    #else
        #pragma comment(lib, "GraphicsDX12_x64_Release.lib")
    #endif
#else
    #ifdef _DEBUG
        #pragma comment(lib, "GraphicsDX12_Win32_Debug.lib")
    #else
        #pragma comment(lib, "GraphicsDX12_Win32_Release.lib")
    #endif
#endif

#endif