#include "pch.h"
#include "Module.h"

#include "../Core/Framework.h"

#include "Device.h"
#include "Command.h"
#include "DescriptorHeap.h"
#include "Output.h"
#include "Pipeline.h"

namespace Framework::GraphicsDX12::Module
{

    Framework::Core::Framework* Framework{ nullptr };
    HDC                         hdc{ NULL };

    Device                          device{};
    Resource::CommonDescriptorHeap  commonDescriptorHeap;
    Output                          output{};
    CommonPipeline                  commonPipeline{};

    void SceneStart()
    {
        assert(hdc == NULL);
        hdc = GetDC(Core::GetGameWindowHandle());

        assert(device.Initialize());
        assert(commonDescriptorHeap.RenderTargetView.Initialize(&device));
        assert(output.Initialize(&device, &commonDescriptorHeap));
        assert(commonPipeline.Initialize(&device, &output, &commonDescriptorHeap));

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
        swprintf_s(str, TEXT("Graphhics Tick: %f"), tick);
        TextOut(hdc, width >> 1, height >> 1, str, (int)wcslen(str));

        commonPipeline.Render();

    }

}

void FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME(class Framework::Core::Framework* framework)
{
    static auto sceneStartEvent{ framework->Event.SceneStartEvent.Insert(Framework::GraphicsDX12::Module::SceneStart) };
    static auto sceneEndEvent{ framework->Event.SceneEndEvent.Insert(Framework::GraphicsDX12::Module::SceneEnd) };
    static auto frameUpdateEvent{ framework->Event.FrameUpdateEvent.Insert(Framework::GraphicsDX12::Module::FrameUpdate) };
}