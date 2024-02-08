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

        //노드 뒤에 아무 노드도 없다면 nullptr를 리턴합니다.
        if (node->next == nullptr)
        {
            return nullptr;
        }

        //마지막 요소를 제거하기 위해선 마지막 요소의 전 요소를 가지고 있어야 합니다.
        //마지막 전 요소를 이용해 마지막 요소를 찾습니다.
        auto lastNode{ node };
        while (lastNode->next->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        //리턴값으로 넘겨주기 위해 마지막 요소를 임시로 보관하고 연결을 끊습니다.
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

                //리턴하기 위해 백업
                auto result{ prev };

                //이전 노드에 이전 노드가 있다면 현재 노드와 연결합니다.
                if (prev->prev != nullptr)
                {
                    prev->prev->next = this;
                }
                prev = prev->prev;

                //연결을 끊고 리턴합니다.
                result->prev = result->next = nullptr;
                return result;

            }

            return nullptr;

        }

        DoubleLinkedListNode* UnlinkNext()
        {

            if (next != nullptr)
            {

                //리턴하기 위해 백업
                auto result{ next };

                //다음 노드에 다음 노드가 있다면 현재 노드와 연결합니다.
                if (next->next != nullptr)
                {
                    next->next->prev = this;
                }
                next = next->next;

                //연결을 끊고 리턴합니다.
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

        //처음 노드 뒤에 노드가 있다면 노드가 리스트로 연결되어 있습니다.
        if (firstNode->next != nullptr)
        {
            firstNode->next->prev   = nullptr;
            firstNode->next         = nullptr;
            return firstNode;
        }

        //처음 노드 뒤에 노드가 없다면 단일 노드입니다.

        return firstNode;

    }

    template<typename Type>
    DoubleLinkedListNode<Type>* UnlinkLastNode(DoubleLinkedListNode<Type>* node)
    {

        auto lastNode{ GetLastNode(node) };
        
        //마지막 노드 앞에 노드가 있다면 노드가 리스트로 연결되어 있습니다.
        if (lastNode->prev != nullptr)
        {
            lastNode->prev->next = nullptr;
            lastNode->prev       = nullptr;
            return lastNode;
        }

        //마지막 노드 앞에 노드가 없다면 단일 노드입니다.

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