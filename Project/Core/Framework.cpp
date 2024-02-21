#include "pch.h"
#include "Framework.h"

#include "Module.h"
#include "ModuleRequireFunction.h"

namespace Framework::Core
{

    LRESULT CALLBACK MessageProcessor(HWND windowHandle, UINT message, WPARAM wparameter, LPARAM lparameter)
    {

        static Framework* framework{ nullptr };

        if (framework != nullptr)
        {
            return framework->MessageProcessor(windowHandle, message, wparameter, lparameter);
        }
        else
        {
            framework = (Framework*)GetWindowLongPtr(windowHandle, GWLP_USERDATA);
            if (framework != nullptr)
            {
                return framework->MessageProcessor(windowHandle, message, wparameter, lparameter);
            }
        }

        return DefWindowProc(windowHandle, message, wparameter, lparameter);

    }

    bool Framework::Initialize(HINSTANCE handle)
    {

        instanceHandle = handle;

        WNDCLASSEX wc;
        wc.cbSize           = sizeof(wc);
        wc.cbWndExtra       = sizeof(this);
        wc.cbClsExtra       = 0;
        wc.hbrBackground    = (HBRUSH)GetStockObject(WHITE_BRUSH);
        wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
        wc.hIcon            = LoadIcon(NULL, IDI_APPLICATION);
        wc.hIconSm          = wc.hIcon;
        wc.hInstance        = instanceHandle;
        wc.lpfnWndProc      = ::Framework::Core::MessageProcessor;
        wc.lpszClassName    = TEXT("FrameworkWindow");
        wc.lpszMenuName     = NULL;
        wc.style            = CS_VREDRAW | CS_HREDRAW;
        RegisterClassEx(&wc);
        
        gameWindowHandle = CreateWindowEx(NULL, TEXT("FrameworkWindow"), TEXT("Game"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 760, NULL, NULL, instanceHandle, nullptr );
        ShowWindow(gameWindowHandle, SW_SHOWDEFAULT);

        SetWindowLongPtr(gameWindowHandle, GWLP_USERDATA, (LONG_PTR)this);

        return true;

    }

    bool Framework::LoadModule(std::wstring_view fileName)
    {

        HMODULE moduleHandle{ LoadLibrary(fileName.data()) };
        if (moduleHandle == NULL)
        {
            return false;
        }

        ModuleSetupFunction setupFunction{ (ModuleSetupFunction)GetProcAddress(moduleHandle, FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME_STRING) };
        if (setupFunction != nullptr)
        {

            setupFunction(this);

        }

        return true;

    }

    void Framework::Run()
    {

        Event.SceneStartEvent.Call();

        MSG msg{};
        ZeroMemory(&msg, sizeof(msg));
        while (msg.message != WM_QUIT)
        {

            if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            else
            {

                Event.FrameUpdateEvent.Call(0.5f);

            }

        }

    }

    LRESULT Framework::MessageProcessor(HWND windowHandle, UINT message, WPARAM wparameter, LPARAM lparameter)
    {

        switch (message)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        }

        return DefWindowProc(windowHandle, message, wparameter, lparameter);

    }

}