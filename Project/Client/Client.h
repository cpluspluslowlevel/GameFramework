//�ܺο��� ����� ����� �� �Ҿ�;� �ϴ� ����Դϴ�.
//������Ʈ ���ο����� ����ؼ� �ȵ˴ϴ�.



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