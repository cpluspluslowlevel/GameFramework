//외부에서 모듈을 사용할 때 불어와야 하는 헤더입니다.
//프로젝트 내부에서는 사용해선 안됩니다.



#ifndef _FRAMEWORK_CLIENT_CLIENT_H_
#define _FRAMEWORK_CLIENT_CLIENT_H_

#define FRAMEWORK_CLIENT_DLL_IMPORT
#include "pch.h"

#ifdef _WIN64
    #ifdef _DEBUG
        #pragma comment(lib, "Client_x64_Debug.lib")
    #else
        #pragma comment(lib, "Client_x64_Release.lib")
    #endif
#else
    #ifdef _DEBUG
        #pragma comment(lib, "Client_Win32_Debug.lib")
    #else
        #pragma comment(lib, "Client_Win32_Release.lib")
    #endif
#endif

#endif