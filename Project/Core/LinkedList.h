#ifndef _FRAMEWORK_CORE_LINKEDLIST_H_
#define _FRAMEWORK_CORE_LINKEDLIST_H_

namespace Framework::Core::DataStruct::LinkedList
{


    template<typename Type>
    class SingleLinkedListNode
    {
    public:

        


    public:
        SingleLinkedListNode() = default;
        SingleLinkedListNode(const Type& v) : value{ v }, next{ nullptr } {}
        SingleLinkedListNode(const SingleLinkedListNode&) = delete;
        SingleLinkedListNode(SingleLinkedListNode&&) noexcept = delete;
        ~SingleLinkedListNode() noexcept = default;
        SingleLinkedListNode& operator=(const SingleLinkedListNode&) = delete;
        SingleLinkedListNode& operator=(SingleLinkedListNode&&) noexcept = delete;


        void LinkNext(SingleLinkedListNode* newNode)
        {

            newNode->next = next;
            next = newNode;

        }

        SingleLinkedListNode* UnlinkNext()
        {

            if (next != nullptr)
            {
                SingleLinkedListNode* result{ next };
                next = next->next;
                return result;
            }

            return nullptr;

        }

        Type                    value;
        SingleLinkedListNode*   next;

    };

    template<typename Type>
    SingleLinkedListNode<Type>* GetLastNode(SingleLinkedListNode<Type>* node)
    {

        SingleLinkedListNode<Type>* lastNode{ node };
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        return lastNode;

    }

    template<typename Type>
    void LinkLastNode(SingleLinkedListNode<Type>* node, SingleLinkedListNode<Type>* newNode)
    {

        GetLastNode(node)->next = newNode;

    }

    template<typename Type>
    SingleLinkedListNode<Type>* UnlinkLastNode(SingleLinkedListNode<Type>* node)
    {

        //��� �ڿ� �ƹ� ��嵵 ���ٸ� nullptr�� �����մϴ�.
        if (node->next == nullptr)
        {
            return nullptr;
        }

        //������ ��Ҹ� �����ϱ� ���ؼ� ������ ����� �� ��Ҹ� ������ �־�� �մϴ�.
        //������ �� ��Ҹ� �̿��� ������ ��Ҹ� ã���ϴ�.
        auto lastNode{ node };
        while (lastNode->next->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        //���ϰ����� �Ѱ��ֱ� ���� ������ ��Ҹ� �ӽ÷� �����ϰ� ������ �����ϴ�.
        auto result{ lastNode->next };
        lastNode->next = nullptr;

        return result;

    }

    template<typename Type>
    SingleLinkedListNode<Type>* SearchNode(SingleLinkedListNode<Type>* node, const Type& value)
    {

        auto loopNode{ node };
        while (loopNode != nullptr)
        {

            if (loopNode->value == value)
            {
                return loopNode;
            }

            loopNode = loopNode->next;

        }

        return nullptr;

    }




    //Double linked list

    ////////////////////////////////////////
    
    template<typename Type>
    class DoubleLinkedListNode
    {
    public:
        DoubleLinkedListNode() : value{}, prev{ nullptr }, next{ nullptr } {}
        DoubleLinkedListNode(const Type& v) : value{ v }, prev{ nullptr }, next{ nullptr } {}
        DoubleLinkedListNode(const DoubleLinkedListNode&) = delete;
        DoubleLinkedListNode(DoubleLinkedListNode&&) noexcept = delete;
        ~DoubleLinkedListNode() noexcept = default;
        DoubleLinkedListNode& operator=(const DoubleLinkedListNode&) = delete;
        DoubleLinkedListNode& operator=(DoubleLinkedListNode&&) noexcept = delete;



        void LinkPrev(DoubleLinkedListNode* newNode)
        {

            newNode->prev = prev;
            newNode->next = this;

            if (prev != nullptr)
            {
                prev->next = newNode;
            }
            prev = newNode;
            

        }

        void LinkNext(DoubleLinkedListNode* newNode)
        {

            newNode->prev = this;
            newNode->next = next;

            if (next != nullptr)
            {
                next->prev = newNode;
            }
            next = newNode;

        }

        DoubleLinkedListNode* UnlinkPrev()
        {

            if (prev != nullptr)
            {

                //�����ϱ� ���� ���
                auto result{ prev };

                //���� ��忡 ���� ��尡 �ִٸ� ���� ���� �����մϴ�.
                if (prev->prev != nullptr)
                {
                    prev->prev->next = this;
                }
                prev = prev->prev;

                //������ ���� �����մϴ�.
                result->prev = result->next = nullptr;
                return result;

            }

            return nullptr;

        }

        DoubleLinkedListNode* UnlinkNext()
        {

            if (next != nullptr)
            {

                //�����ϱ� ���� ���
                auto result{ next };

                //���� ��忡 ���� ��尡 �ִٸ� ���� ���� �����մϴ�.
                if (next->next != nullptr)
                {
                    next->next->prev = this;
                }
                next = next->next;

                //������ ���� �����մϴ�.
                result->prev = result->next = nullptr;
                return result;

            }

            return nullptr;

        }

        Type                    value;
        DoubleLinkedListNode*   prev;
        DoubleLinkedListNode*   next;

    };

    template<typename Type>
    DoubleLinkedListNode<Type>* GetFirstNode(DoubleLinkedListNode<Type>* node)
    {

        auto firstNode{ node };
        while (firstNode->prev != nullptr)
        {
            firstNode = firstNode->prev;
        }

        return firstNode;

    }

    template<typename Type>
    const DoubleLinkedListNode<Type>* GetFirstNode(const DoubleLinkedListNode<Type>* node)
    {

        auto firstNode{ node };
        while (firstNode->prev != nullptr)
        {
            firstNode = firstNode->prev;
        }

        return firstNode;

    }

    template<typename Type>
    DoubleLinkedListNode<Type>* GetLastNode(DoubleLinkedListNode<Type>* node)
    {

        auto lastNode{ node };
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        return lastNode;

    }

    template<typename Type>
    const DoubleLinkedListNode<Type>* GetLastNode(const DoubleLinkedListNode<Type>* node)
    {

        auto lastNode{ node };
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        return lastNode;

    }
    
    template<typename Type>
    void LinkFirstNode(DoubleLinkedListNode<Type>* node, DoubleLinkedListNode<Type>* newNode)
    {

        auto firstNode{ GetFirstNode(node) };
        firstNode->prev = newNode;
        newNode->next = firstNode;

    }

    template<typename Type>
    void LinkLastNode(DoubleLinkedListNode<Type>* node, DoubleLinkedListNode<Type>* newNode)
    {

        auto lastNode{ GetLastNode(node) };
        lastNode->next = newNode;
        newNode->prev = lastNode;

    }

    template<typename Type>
    DoubleLinkedListNode<Type>* UnlinkFirstNode(DoubleLinkedListNode<Type>* node)
    {

        auto firstNode{ GetFirstNode(node) };

        //ó�� ��� �ڿ� ��尡 �ִٸ� ��尡 ����Ʈ�� ����Ǿ� �ֽ��ϴ�.
        if (firstNode->next != nullptr)
        {
            firstNode->next->prev   = nullptr;
            firstNode->next         = nullptr;
            return firstNode;
        }

        //ó�� ��� �ڿ� ��尡 ���ٸ� ���� ����Դϴ�.

        return firstNode;

    }

    template<typename Type>
    DoubleLinkedListNode<Type>* UnlinkLastNode(DoubleLinkedListNode<Type>* node)
    {

        auto lastNode{ GetLastNode(node) };
        
        //������ ��� �տ� ��尡 �ִٸ� ��尡 ����Ʈ�� ����Ǿ� �ֽ��ϴ�.
        if (lastNode->prev != nullptr)
        {
            lastNode->prev->next = nullptr;
            lastNode->prev       = nullptr;
            return lastNode;
        }

        //������ ��� �տ� ��尡 ���ٸ� ���� ����Դϴ�.

        return lastNode;

    }

    template<typename Type>
    DoubleLinkedListNode<Type>* SearchNodePrev(DoubleLinkedListNode<Type>* node, const Type& value)
    {

        auto loopNode{ node };
        while (loopNode != nullptr)
        {

            if (loopNode->value == value)
            {
                return loopNode;
            }

            loopNode = loopNode->prev;

        }

        return nullptr;

    }

    template<typename Type>
    const DoubleLinkedListNode<Type>* SearchNodePrev(const DoubleLinkedListNode<Type>* node, const Type& value)
    {

        auto loopNode{ node };
        while (loopNode != nullptr)
        {

            if (loopNode->value == value)
            {
                return loopNode;
            }

            loopNode = loopNode->prev;

        }

        return nullptr;

    }

    template<typename Type>
    DoubleLinkedListNode<Type>* SearchNodeNext(DoubleLinkedListNode<Type>* node, const Type& value)
    {

        auto loopNode{ node };
        while (loopNode != nullptr)
        {

            if (loopNode->value == value)
            {
                return loopNode;
            }

            loopNode = loopNode->next;

        }

        return nullptr;

    }

    template<typename Type>
    const DoubleLinkedListNode<Type>* SearchNodeNext(const DoubleLinkedListNode<Type>* node, const Type& value)
    {

        auto loopNode{ node };
        while (loopNode != nullptr)
        {

            if (loopNode->value == value)
            {
                return loopNode;
            }

            loopNode = loopNode->next;

        }

        return nullptr;

    }


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

#endif