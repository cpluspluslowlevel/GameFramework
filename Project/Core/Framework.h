#ifndef _FRAMEWORK_CORE_FRAMEWORK_H_
#define _FRAMEWORK_CORE_FRAMEWORK_H_

namespace Framework::Core
{

    



    /// <summary>
    /// �����ӿ�ũ���� ó���ϴ� �̺�Ʈ�� �����ڸ� �����ϴ� Ŭ�����Դϴ�.
    /// </summary>
    /// <typeparam name="FunctionType"></typeparam>
    template<typename FunctionType>
    class FRAMEWORK_CORE_DLL_CLASS FrameworkEvent
    {
    public:

        using NodeType = DataStruct::LinkedList::DoubleLinkedListNode<std::function<FunctionType>>;

        /// <summary>
        /// ��ü�� �ı��Ǹ� �̺�Ʈ ������ �����ϴ�.
        /// </summary>
        class EventNode
        {
        public:
            EventNode(NodeType* node) : m_node{ node } {}                            //����, �̵��� ���� �ʽ��ϴ�.
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
        FrameworkEvent() : m_head{}, m_tail{}                            //����, �̵��� ���� �ʽ��ϴ�.
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
        /// �̺�Ʈ�� ����մϴ�.
        /// </summary>
        /// <param name="funtion">�̺�Ʈ �߻��� ȣ��� �Լ�</param>
        /// <returns>��ϵ� �̺�Ʈ�� ����� ��ü. �� ��ü�� �ı��Ǹ� �̺�Ʈ ������ ���Դϴ�.</returns>
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
        Framework() = default;                            //����, �̵��� ���� �ʽ��ϴ�.
        Framework(const Framework&) = delete;
        Framework(Framework&&) noexcept = delete;
        ~Framework() noexcept = default;
        Framework& operator=(const Framework&) = delete;
        Framework& operator=(Framework&&) noexcept = delete;


        bool Initialize(HINSTANCE instanceHandle);

        /// <summary>
        /// ����� �ҷ��ɴϴ�.
        /// </summary>
        bool LoadModule(std::wstring_view fileName);


        /// <summary>
        /// �����ӿ�ũ�� �����մϴ�.
        /// </summary>
        void Run();


        /// <summary>
        /// �޽��� ���ν����� ó���մϴ�.
        /// GUI����� ���������� �����ϱ� ���� �ӽ÷� ����ϴ� �Լ��Դϴ�.
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