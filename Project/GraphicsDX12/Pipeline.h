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
        CommonPipeline() = default;                            //복사, 이동은 하지 않습니다.
        CommonPipeline(const CommonPipeline&) = delete;
        CommonPipeline(CommonPipeline&&) noexcept = delete;
        ~CommonPipeline() noexcept = default;
        CommonPipeline& operator=(const CommonPipeline&) = delete;
        CommonPipeline& operator=(CommonPipeline&&) noexcept = delete;



        /// <summary>
        /// 초기화합니다.
        /// </summary>
        /// <param name="device">디아비스 객체</param>
        /// <param name="output">랜더링될 대상</param>
        /// <returns>성공 유무</returns>
        bool Initialize(class Device* device, class Output* output, Resource::CommonDescriptorHeap* commonDescriptorHeap);



        /// <summary>
        /// 렌더링을 진행합니다.
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