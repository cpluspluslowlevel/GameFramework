#ifndef _FRAMEWORK_CORE_FRAMEWORK_H_
#define _FRAMEWORK_CORE_FRAMEWORK_H_

namespace Framework::Core
{

    



    /// <summary>
    /// 프레임워크에서 처리하는 이벤트의 수신자를 보관하는 클레스입니다.
    /// </summary>
    /// <typeparam name="FunctionType"></typeparam>
    template<typename FunctionType>
    class FRAMEWORK_CORE_DLL_CLASS FrameworkEvent
    {
    public:

        using NodeType = DataStruct::LinkedList::DoubleLinkedListNode<std::function<FunctionType>>;

        /// <summary>
        /// 객체가 파괴되면 이벤트 연결을 끊습니다.
        /// </summary>
        class EventNode
        {
        public:
            EventNode(NodeType* node) : m_node{ node } {}                            //복사, 이동은 하지 않습니다.
            EventNode(const EventNode&) = delete;
            EventNode(EventNode&&) noexcept = delete;
            ~EventNode() noexcept
            {
                m_node->prev->next = m_node->next;
                m_node->next->prev = m_node->prev;
                delete m_node;
            }
            EventNode& operator=(const EventNode&) = delete;
            EventNode& operator=(EventNode&&) noexcept = delete;

        private:

            NodeType* m_node;

        };

    public:
        FrameworkEvent() : m_head{}, m_tail{}                            //복사, 이동은 하지 않습니다.
        {
            m_head.prev = nullptr;
            m_head.next = &m_tail;
            m_tail.prev = &m_head;
            m_tail.next = nullptr;
        }
        FrameworkEvent(const FrameworkEvent&) = delete;
        FrameworkEvent(FrameworkEvent&&) noexcept = delete;
        ~FrameworkEvent() noexcept = default;
        FrameworkEvent& operator=(const FrameworkEvent&) = delete;
        FrameworkEvent& operator=(FrameworkEvent&&) noexcept = delete;


        /// <summary>
        /// 이벤트를 등록합니다.
        /// </summary>
        /// <param name="funtion">이벤트 발생시 호출될 함수</param>
        /// <returns>등록된 이벤트와 연결된 객체. 이 객체가 파괴되면 이벤트 연결이 끊입니다.</returns>
        EventNode* Insert(std::function<FunctionType> funtion)
        {
            
            NodeType* newNode{ new NodeType{funtion} };
            newNode->prev = m_tail.prev;
            newNode->next = &m_tail;

            m_tail.prev->next   = newNode;
            m_tail.prev         = newNode;

            return new EventNode{ newNode };

        }

        template<typename... Args>
        void Call(Args... args)
        {

            auto node{ m_head.next };
            while (node != &m_tail)
            {
                node->value(args...);
                node = node->next;
            }

        }

    private:

        NodeType m_head;
        NodeType m_tail;

    };


    template class FRAMEWORK_CORE_DLL_CLASS FrameworkEvent<void()>;
    template class FRAMEWORK_CORE_DLL_CLASS FrameworkEvent<void(float)>;
    class FRAMEWORK_CORE_DLL_CLASS Framework
    {
    public:

        class EventContainer
        {
        public:
            FrameworkEvent<void()>          SceneStartEvent;
            FrameworkEvent<void()>          SceneEndEvent;
            FrameworkEvent<void(float)>     FrameUpdateEvent;
        };

    public:
        Framework() = default;                            //복사, 이동은 하지 않습니다.
        Framework(const Framework&) = delete;
        Framework(Framework&&) noexcept = delete;
        ~Framework() noexcept = default;
        Framework& operator=(const Framework&) = delete;
        Framework& operator=(Framework&&) noexcept = delete;


        bool Initialize(HINSTANCE instanceHandle);

        /// <summary>
        /// 모듈을 불러옵니다.
        /// </summary>
        bool LoadModule(std::wstring_view fileName);


        /// <summary>
        /// 프레임워크를 구동합니다.
        /// </summary>
        void Run();


        /// <summary>
        /// 메시지 프로시저를 처리합니다.
        /// GUI기능을 본격적으로 지원하기 전에 임시로 사용하는 함수입니다.
        /// </summary>
        /// <param name="windowHandle"></param>
        /// <param name="message"></param>
        /// <param name="wparameter"></param>
        /// <param name="lparameter"></param>
        /// <returns></returns>
        LRESULT MessageProcessor(HWND windowHandle, UINT message, WPARAM wparameter, LPARAM lparameter);


        EventContainer      Event;

    private:


    };

}

#endif