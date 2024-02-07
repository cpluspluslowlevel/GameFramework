#ifndef _FRAMEWORK_CORE_LINKEDLIST_H_
#define _FRAMEWORK_CORE_LINKEDLIST_H_

namespace Framework::Core::DataStruct::LinkedList
{


    template<typename Type>
    class SingleLinkedListNode
    {
    public:

        


    public:
        SingleLinkedListNode() : value{}, next{ nullptr } {}

        SingleLinkedListNode(const Type& v) : value{ v }, next{ nullptr } {}

        SingleLinkedListNode(const Type& v, SingleLinkedListNode* n) : value{ v }, next{ n } {}

        SingleLinkedListNode(const SingleLinkedListNode& lvalue) : value{ lvalue.value }, next{ lvalue.next } {}

        SingleLinkedListNode(SingleLinkedListNode&& rvalue) noexcept : value{ std::move(rvalue.value) },
                                                                       next{ rvalue.next }
        {
            rvalue.next = nullptr;      //value가 무거운 형식일 수도 있기 때문에 성능을 위해 rvalue.value를 초기화 하진 않습니다.
        }

        SingleLinkedListNode& operator=(const SingleLinkedListNode& lvalue)
        {
            value   = lvalue.value;
            next    = lvalue.next;
            return *this;
        }

        SingleLinkedListNode& operator=(SingleLinkedListNode&& rvalue) noexcept
        {
            value = rvalue.value;
            next  = rvalue.next;

            rvalue.next = nullptr;      //value가 무거운 형식일 수도 있기 때문에 성능을 위해 rvalue.value를 초기화 하진 않습니다.

            return *this;
        }

        ~SingleLinkedListNode() noexcept {}


        SingleLinkedListNode* FindLastNode()
        {

            SingleLinkedListNode* lastNode{ this };
            while (lastNode->next != nullptr)
            {
                lastNode = lastNode->next;
            }

            return lastNode;

        }


        void LinkNext(SingleLinkedListNode* newNode)
        {

            //이미 뒤에 어떤 노드가 있다면 새로운 노드(또는 리스트)의 뒤에 붙여줍니다.
            //노드가 연결된 리스트이면 리스트 전체가 붙습니다.
            if (next != nullptr)
            {
                newNode->FindLastNode()->next  = next;
            }

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
    void LinkLast(SingleLinkedListNode<Type>* node, SingleLinkedListNode<Type>* newNode)
    {

        node->FindLastNode()->next = newNode;

    }

    template<typename Type>
    SingleLinkedListNode<Type>* UnlinkLast(SingleLinkedListNode<Type>* node)
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
    SingleLinkedListNode<Type>* FindFirst(SingleLinkedListNode<Type>* node, const Type& value)
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

}

#endif