//�ܺο��� ����� ����� �� �Ҿ�;� �ϴ� ����Դϴ�.
//������Ʈ ���ο����� ����ؼ� �ȵ˴ϴ�.



#ifndef _FRAMEWORK_GAME_GAME_H_
#define _FRAMEWORK_GAME_GAME_H_

#define FRAMEWORK_GAME_DLL_IMPORT
#include "pch.h"

#ifdef _WIN64
    #ifdef _DEBUG
        #pragma comment(lib, "Game_x64_Debug.lib")
    #else
        #pragma comment(lib, "Game_x64_Release.lib")
    #endif
#else
    #ifdef _DEBUG
        #pragma comment(lib, "Game_Win32_Debug.lib")
    #else
        #pragma comment(lib, "Game_Win32_Release.lib")
    #endif
#endif

#endif