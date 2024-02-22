#include "pch.h"

namespace Framework::Core
{

    HINSTANCE   instanceHandle{ NULL };
    HWND        gameWindowHandle{ NULL };


    void SetInstanceHandle(HINSTANCE instanceHandle)
    {
        assert(::Framework::Core::instanceHandle == NULL);
        ::Framework::Core::instanceHandle = instanceHandle;
    }

    void SetGameWindowHandle(HWND windowHandle)
    {
        assert(gameWindowHandle == NULL);
        gameWindowHandle = windowHandle;
    }

    HINSTANCE GetInstanceHandle()
    {
        return instanceHandle;
    }

    HWND GetGameWindowHandle()
    {
        return gameWindowHandle;
    }

}