//�ܺο��� ����� ����� �� �Ҿ�;� �ϴ� ����Դϴ�.
//������Ʈ ���ο����� ����ؼ� �ȵ˴ϴ�.



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