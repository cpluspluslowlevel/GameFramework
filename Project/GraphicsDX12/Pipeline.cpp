#include "pch.h"
#include "Pipeline.h"

#include "Device.h"
#include "Command.h"
#include "DescriptorHeap.h"
#include "Output.h"

namespace Framework::GraphicsDX12
{



    bool CommonPipeline::Initialize(Device* device, Output* output, Resource::CommonDescriptorHeap* commonDescriptorHeap)
    {

        m_output = output;

        if (FAILED(device->GetDevice()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(ID3D12CommandAllocator), (void**)m_commandAllocator.ResetByOutParameter())))
        {
            return false;
        }

        if (FAILED(device->GetDevice()->CreateCommandList(NULL, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator, nullptr, __uuidof(ID3D12CommandList), (void**)m_commandList.ResetByOutParameter())))
        {
            return false;
        }

        m_commandList->Close();     //Reset함수를 호출하기 위해선 Close상태이어야 해서 미리 호출해 놓습니다.



        if (FAILED(device->GetDevice()->CreateFence(0, D3D12_FENCE_FLAG_NONE, __uuidof(ID3D12Fence), (void**)m_fence.ResetByOutParameter())))
        {
            return false;
        }

        m_fenceEventHandle = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (m_fenceEventHandle == NULL)
        {
            return false;
        }

        m_fenceValue = 0;

        return true;

    }

    void CommonPipeline::Render()
    {

        m_commandAllocator->Reset();
        m_commandList->Reset(m_commandAllocator, nullptr);

        m_output->MakeClearCommand(m_commandList);

        m_commandList->Close();




        auto                commandQueue{ m_output->GetCommandQueue() };
        ID3D12CommandList*  commandList{ m_commandList };
        commandQueue->ExecuteCommandLists(1, &commandList);

        m_output->Present();


        m_fenceValue++;

        commandQueue->Signal(m_fence, m_fenceValue);

        if (m_fence->GetCompletedValue() < m_fenceValue)
        {

            m_fence->SetEventOnCompletion(m_fenceValue, m_fenceEventHandle);

            ::WaitForSingleObject(m_fenceEventHandle, INFINITE);

        }


    }

    Output* CommonPipeline::GetOutput()
    {
        return m_output;
    }

    const Output* CommonPipeline::GetOutput() const
    {
        return m_output;
    }

}