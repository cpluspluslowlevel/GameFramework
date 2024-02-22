#include "pch.h"
#include "Module.h"

#include "../Core/Framework.h"

namespace Framework::Game::Module
{

    Framework::Core::Framework* Framework{ nullptr };
    HDC                         hdc{ NULL };

    void SceneStart()
    {
        assert(hdc == NULL);
        hdc = GetDC(Core::GetGameWindowHandle());
    }

    void SceneEnd()
    {
        if (hdc != NULL)
        {
            ReleaseDC(Core::GetGameWindowHandle(), hdc);
        }
    }

    void FrameUpdate(float tick)
    {

        RECT windowRect{};
        GetClientRect(Core::GetGameWindowHandle(), &windowRect);

        UINT width{ (UINT)windowRect.right - (UINT)windowRect.left };
        UINT height{ (UINT)windowRect.bottom - (UINT)windowRect.top };

        //Rectangle(hdc, 0, 0, width, height);
        
        TCHAR str[256];
        swprintf_s(str, TEXT("Game Tick: %f"), tick);
        TextOut(hdc, width >> 1, (height >> 1) - 100, str, (int)wcslen(str));

    }

}

void FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME(class Framework::Core::Framework* framework)
{

    framework->LoadModule(L"GraphicsDX12_x64_Debug.dll");

    static auto sceneStartEvent{ framework->Event.SceneStartEvent.Insert(Framework::Game::Module::SceneStart) };
    static auto sceneEndEvent{ framework->Event.SceneEndEvent.Insert(Framework::Game::Module::SceneEnd) };
    static auto frameUpdateEvent{ framework->Event.FrameUpdateEvent.Insert(Framework::Game::Module::FrameUpdate) };

}