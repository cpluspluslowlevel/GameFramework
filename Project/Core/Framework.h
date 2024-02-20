#ifndef _FRAMEWORK_CORE_FRAMEWORK_H_
#define _FRAMEWORK_CORE_FRAMEWORK_H_

namespace Framework::Core
{

    class FRAMEWORK_CORE_DLL_CLASS Framework
    {
    public:
        Framework() = default;                            //복사, 이동은 하지 않습니다.
        Framework(const Framework&) = delete;
        Framework(Framework&&) noexcept = delete;
        ~Framework() noexcept = default;
        Framework& operator=(const Framework&) = delete;
        Framework& operator=(Framework&&) noexcept = delete;

        
        /// <summary>
        /// 모듈을 불러옵니다.
        /// </summary>
        bool LoadModule(std::wstring_view fileName);


        /// <summary>
        /// 프레임워크를 구동합니다.
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