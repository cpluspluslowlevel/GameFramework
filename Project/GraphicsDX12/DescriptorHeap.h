#ifndef _FRAMEWORK_GRAPHICSDX12_DESCRIPTORHEAP_H_
#define _FRAMEWORK_GRAPHICSDX12_DESCRIPTORHEAP_H_

namespace Framework::GraphicsDX12
{
    class Device;
}

namespace Framework::GraphicsDX12::Resource
{

    class FRAMEWORK_GRAPHICSDX12_DLL_CLASS RTVCommonDescriptorHeap
    {
    public:

        struct GROUP
        {

            COMPTR<ID3D12DescriptorHeap> descriptorHeap;

            UInt32          size;

        };

        using GroupList = Core::DataStruct::Container::List<GROUP>;

    public:
        RTVCommonDescriptorHeap() = default;                            //복사, 이동은 하지 않습니다.
        RTVCommonDescriptorHeap(const RTVCommonDescriptorHeap&) = delete;
        RTVCommonDescriptorHeap(RTVCommonDescriptorHeap&&) noexcept = delete;
        ~RTVCommonDescriptorHeap() noexcept = default;
        RTVCommonDescriptorHeap& operator=(const RTVCommonDescriptorHeap&) = delete;
        RTVCommonDescriptorHeap& operator=(RTVCommonDescriptorHeap&&) noexcept = delete;



        bool Initialize(class Device* device);


        D3D12_CPU_DESCRIPTOR_HANDLE MakeDescriptorHeap(UInt32 size);

    private:

        GroupList::NodeType* CreateGroup();

        class Device*                               m_device;

        UInt32                                      m_interval;

        GroupList    m_groupList;

    };


    class FRAMEWORK_GRAPHICSDX12_DLL_CLASS CommonDescriptorHeap
    {
    public:


        RTVCommonDescriptorHeap RenderTargetView;

        
    };


}

#endif