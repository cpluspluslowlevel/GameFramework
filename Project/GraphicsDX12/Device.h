#ifndef _FRAMEWORK_GRAPHICSDX12_DEVICE_H_
#define _FRAMEWORK_GRAPHICSDX12_DEVICE_H_

namespace Framework::GraphicsDX12
{


    class FRAMEWORK_GRAPHICSDX12_DLL_CLASS Device
    {
    public:
        Device() = default;                            //복사, 이동은 하지 않습니다.
        Device(const Device&) = delete;
        Device(Device&&) noexcept = delete;
        ~Device() noexcept = default;
        Device& operator=(const Device&) = delete;
        Device& operator=(Device&&) noexcept = delete;

        bool Initialize();

        COMPTR<ID3D12Device> GetDevice();

    private:

        COMPTR<ID3D12Device>    m_device;
        COMPTR<ID3D12Debug>     m_debug;


    };


}

#endif