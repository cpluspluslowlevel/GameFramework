//�ܺο��� ����� ����� �� �Ҿ�;� �ϴ� ����Դϴ�.
//������Ʈ ���ο����� ����ؼ� �ȵ˴ϴ�.



#ifndef _FRAMEWORK_PROJECTTEMPLATE_PROJECTTEMPLATE_H_
#define _FRAMEWORK_PROJECTTEMPLATE_PROJECTTEMPLATE_H_

#define FRAMEWORK_PROJECTTEMPLATE_DLL_IMPORT
#include "pch.h"

#ifdef _WIN64
    #ifdef _DEBUG
        #pragma comment(lib, "ProjectTemplate_x64_Debug.lib")
    #else
        #pragma comment(lib, "ProjectTemplate_x64_Release.lib")
    #endif
#else
    #ifdef _DEBUG
        #pragma comment(lib, "ProjectTemplate_Win32_Debug.lib")
    #else
        #pragma comment(lib, "ProjectTemplate_Win32_Release.lib")
    #endif
#endif

#endif