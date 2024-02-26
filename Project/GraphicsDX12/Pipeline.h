#ifndef _FRAMEWORK_GRAPHICSDX12_PIPELIEN_H_
#define _FRAMEWORK_GRAPHICSDX12_PIPELIEN_H_

namespace Framework::GraphicsDX12
{

    namespace Resource
    {
        class CommonDescriptorHeap;
    }

    class CommonPipeline
    {
    public:
        CommonPipeline() = default;                            //����, �̵��� ���� �ʽ��ϴ�.
        CommonPipeline(const CommonPipeline&) = delete;
        CommonPipeline(CommonPipeline&&) noexcept = delete;
        ~CommonPipeline() noexcept = default;
        CommonPipeline& operator=(const CommonPipeline&) = delete;
        CommonPipeline& operator=(CommonPipeline&&) noexcept = delete;



        /// <summary>
        /// �ʱ�ȭ�մϴ�.
        /// </summary>
        /// <param name="device">��ƺ� ��ü</param>
        /// <param name="output">�������� ���</param>
        /// <returns>���� ����</returns>
        bool Initialize(class Device* device, class Output* output, Resource::CommonDescriptorHeap* commonDescriptorHeap);



        /// <summary>
        /// �������� �����մϴ�.
        /// </summary>
        void Render();




        //Getter

        class Output*           GetOutput();
        const class Output*     GetOutput() const;

    private:

        class Output* m_output;

        COMPTR<ID3D12CommandAllocator>          m_commandAllocator;
        COMPTR<ID3D12GraphicsCommandList>       m_commandList;

        COMPTR<ID3D12Fence> m_fence;
        HANDLE              m_fenceEventHandle;
        UInt64              m_fenceValue;

    };

}

#endif