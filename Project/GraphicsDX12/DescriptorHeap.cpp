#include "pch.h"
#include "DescriptorHeap.h"

#include "Device.h"

namespace Framework::GraphicsDX12::Resource
{

    bool RTVCommonDescriptorHeap::Initialize(Device* device)
    {

        m_device = device;
        m_interval = m_device->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

        return true;
        
    }

    D3D12_CPU_DESCRIPTOR_HANDLE RTVCommonDescriptorHeap::MakeDescriptorHeap(UInt32 size)
    {

        assert(size <= RESOURCE_RTV_COMMONDESCRIPTORHEAP_CAPACITY);

        //���� ������ �ִٸ� �Ѱ��ݴϴ�.
        auto node{ m_groupList.GetHeadNode() };
        while (node != nullptr)
        {

            if (node->value.size + size <= RESOURCE_RTV_COMMONDESCRIPTORHEAP_CAPACITY)
            {

                D3D12_CPU_DESCRIPTOR_HANDLE handle{ node->value.descriptorHeap->GetCPUDescriptorHandleForHeapStart() };
                handle.ptr += node->value.size;

                node->value.size += size;

                return handle;

            }

            node = node->next;



        }


        //���� ������ ���ٸ� ���ο� ������ �����մϴ�.
        D3D12_CPU_DESCRIPTOR_HANDLE handle{ 0 };
        auto newGroup = CreateGroup();
        if (newGroup != nullptr)
        {
            handle              = newGroup->value.descriptorHeap->GetCPUDescriptorHandleForHeapStart();
            newGroup->value.size    = size;
        }

        return handle;

    }

    RTVCommonDescriptorHeap::GroupList::NodeType* RTVCommonDescriptorHeap::CreateGroup()
    {

        GROUP group{};
        group.size = 0;

        D3D12_DESCRIPTOR_HEAP_DESC desc;
        desc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        desc.NumDescriptors = RESOURCE_RTV_COMMONDESCRIPTORHEAP_CAPACITY;
        desc.NodeMask       = NULL;
        desc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        if (FAILED(m_device->GetDevice()->CreateDescriptorHeap(&desc, __uuidof(ID3D12DescriptorHeap), (void**)group.descriptorHeap.ResetByOutParameter())))
        {
            return nullptr;
        }

        m_groupList.InsertFirst(group);

        return m_groupList.GetHeadNode();

    }

}