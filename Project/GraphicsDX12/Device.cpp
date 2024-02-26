#include "pch.h"
#include "Device.h"

namespace Framework::GraphicsDX12
{



    bool Device::Initialize()
    {

        //Direct3D 12 COM객체를 생성합니다.

#ifdef _DEBUG
        if (FAILED(D3D12GetDebugInterface(__uuidof(ID3D12Debug), (void**)m_debug.ResetByOutParameter())))
        {
            return false;
        }

        m_debug->EnableDebugLayer();
#endif

        if (FAILED(D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), (void**)m_device.ResetByOutParameter())))
        {
            return false;
        }

        return true;

    }

    COMPTR<ID3D12Device> Device::GetDevice()
    {
        return m_device;
    }

}