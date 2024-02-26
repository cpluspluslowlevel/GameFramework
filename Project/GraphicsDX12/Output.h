#ifndef _FRAMEWORK_GRAPHICSDX12_OUTPUT_H_
#define _FRAMEWORK_GRAPHICSDX12_OUTPUT_H_


namespace Framework::GraphicsDX12
{

    namespace Resource
    {
        class CommonDescriptorHeap;
    }

    class FRAMEWORK_GRAPHICSDX12_DLL_CLASS Output
    {
    public:
        Output() = default;                            //����, �̵��� ���� �ʽ��ϴ�.
        Output(const Output&) = delete;
        Output(Output&&) noexcept = delete;
        ~Output() noexcept = default;
        Output& operator=(const Output&) = delete;
        Output& operator=(Output&&) noexcept = delete;

        bool Initialize(class Device* device, Resource::CommonDescriptorHeap* commonDescriptorHeap);


        /// <summary>
        /// ����۸� ����� ����� ����ϴ�.
        /// </summary>
        void MakeClearCommand(COMPTR<ID3D12GraphicsCommandList> commandList);


        //����۸� ȭ�鿡 ǥ���մϴ�.
        void Present();

        COMPTR<ID3D12CommandQueue> GetCommandQueue();


    private:

        COMPTR<ID3D12CommandQueue>  m_commandQueue;
        COMPTR<IDXGISwapChain1>     m_swapchain;

        COMPTR<ID3D12Resource> m_resource;

        COMPTR<ID3D12Resource>          m_backbufferArray[OUTPUT_RTV_NUMBER];
        D3D12_CPU_DESCRIPTOR_HANDLE     m_rtvDescriptorHandleArray[OUTPUT_RTV_NUMBER];

        UInt32 m_backbufferIndex;

    };

}

#endif