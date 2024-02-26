#include "pch.h"
#include "Output.h"

#include "Device.h"
#include "DescriptorHeap.h"

namespace Framework::GraphicsDX12
{

    

    bool Output::Initialize(Device* device, Resource::CommonDescriptorHeap* commonDescriptorHeap)
    {


        //CommandQueue 持失

        D3D12_COMMAND_QUEUE_DESC commandQueueDesc;
        commandQueueDesc.Type       = D3D12_COMMAND_LIST_TYPE_DIRECT;
        commandQueueDesc.Priority   = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
        commandQueueDesc.Flags      = D3D12_COMMAND_QUEUE_FLAG_NONE;
        commandQueueDesc.NodeMask   = NULL;

        if (FAILED(device->GetDevice()->CreateCommandQueue(&commandQueueDesc, __uuidof(ID3D12CommandQueue), (void**)m_commandQueue.ResetByOutParameter())))
        {
            return false;
        }


        //Swapchain 持失
        
        DXGI_SWAP_CHAIN_DESC1 swapchainDesc;
        swapchainDesc.Width                 = 0;
        swapchainDesc.Height                = 0;
        swapchainDesc.Format                = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapchainDesc.Stereo                = false;
        swapchainDesc.SampleDesc.Count      = 1;
        swapchainDesc.SampleDesc.Quality    = 0;
        swapchainDesc.BufferUsage           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapchainDesc.BufferCount           = 2;
        swapchainDesc.Scaling               = DXGI_SCALING_NONE;
        swapchainDesc.SwapEffect            = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        swapchainDesc.AlphaMode             = DXGI_ALPHA_MODE_UNSPECIFIED;
        swapchainDesc.Flags                 = NULL;

        COMPTR<IDXGIFactory2> factory;
        if (FAILED(CreateDXGIFactory2(NULL, __uuidof(IDXGIFactory2), (void**)factory.ResetByOutParameter())))
        {
            return false;
        }

        if (FAILED(factory->CreateSwapChainForHwnd(m_commandQueue, Core::GetGameWindowHandle(), &swapchainDesc, nullptr, nullptr, m_swapchain.ResetByOutParameter())))
        {
            return false;
        }

        auto handle{ commonDescriptorHeap->RenderTargetView.MakeDescriptorHeap(OUTPUT_RTV_NUMBER) };
        if (handle.ptr == 0)
        {
            return false;
        }

        for (UInt32 i = 0; i < OUTPUT_RTV_NUMBER; ++i)
        {

            m_swapchain->GetBuffer(i, __uuidof(ID3D12Resource), (void**)&m_backbufferArray[i]);

            m_rtvDescriptorHandleArray[i]           = handle;
            m_rtvDescriptorHandleArray[i].ptr       += i * device->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
            device->GetDevice()->CreateRenderTargetView(m_backbufferArray[i], nullptr, m_rtvDescriptorHandleArray[i]);

        }

        return true;

    }

    void Output::MakeClearCommand(COMPTR<ID3D12GraphicsCommandList> commandList)
    {

        {
            D3D12_RESOURCE_BARRIER barrier{};
            barrier.Type                    = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
            barrier.Transition.pResource    = m_backbufferArray[m_backbufferIndex];
            barrier.Transition.Subresource  = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
            barrier.Transition.StateBefore  = D3D12_RESOURCE_STATE_PRESENT;
            barrier.Transition.StateAfter   = D3D12_RESOURCE_STATE_RENDER_TARGET;
            barrier.Flags                   = D3D12_RESOURCE_BARRIER_FLAG_NONE;
            commandList->ResourceBarrier(1, &barrier);
        }

        Float32 color[4]{ 0.0f, 0.0f, 1.0f, 1.0f };
        commandList->ClearRenderTargetView(m_rtvDescriptorHandleArray[m_backbufferIndex], color, 0, nullptr);
        commandList->OMSetRenderTargets(1, &m_rtvDescriptorHandleArray[m_backbufferIndex], false, nullptr);


        {
            D3D12_RESOURCE_BARRIER barrier{};
            barrier.Type                    = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
            barrier.Transition.pResource    = m_backbufferArray[m_backbufferIndex];
            barrier.Transition.Subresource  = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
            barrier.Transition.StateBefore  = D3D12_RESOURCE_STATE_RENDER_TARGET;
            barrier.Transition.StateAfter   = D3D12_RESOURCE_STATE_PRESENT;
            barrier.Flags                   = D3D12_RESOURCE_BARRIER_FLAG_NONE;
            commandList->ResourceBarrier(1, &barrier);
        }


    }

    void Output::Present()
    {
        m_swapchain->Present(0, NULL);
        m_backbufferIndex = (m_backbufferIndex + 1) % OUTPUT_RTV_NUMBER;
    }

    COMPTR<ID3D12CommandQueue> Output::GetCommandQueue()
    {
        return m_commandQueue;
    }

}