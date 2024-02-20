#ifndef _FRAMEWORK_CORE_FRAMEWORK_H_
#define _FRAMEWORK_CORE_FRAMEWORK_H_

namespace Framework::Core
{

    class FRAMEWORK_CORE_DLL_CLASS Framework
    {
    public:
        Framework() = default;                            //����, �̵��� ���� �ʽ��ϴ�.
        Framework(const Framework&) = delete;
        Framework(Framework&&) noexcept = delete;
        ~Framework() noexcept = default;
        Framework& operator=(const Framework&) = delete;
        Framework& operator=(Framework&&) noexcept = delete;

        
        /// <summary>
        /// ����� �ҷ��ɴϴ�.
        /// </summary>
        bool LoadModule(std::wstring_view fileName);


        /// <summary>
        /// �����ӿ�ũ�� �����մϴ�.
        /// </summary>
        void Run();


    private:


    };

    template<typename FunctionType>
    class FRAMEWORK_CORE_DLL_CLASS FrameworkEvent
    {
    public:

    private:

        DataStruct::LinkedList::DoubleLinkedListNode<std::function<FunctionType>> m_head;
        DataStruct::LinkedList::DoubleLinkedListNode<std::function<FunctionType>> m_tail;

    };

}

#endif