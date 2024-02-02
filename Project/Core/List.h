#ifndef _FRAMEWORK_CORE_MODULE_H_
#define _FRAMEWORK_CORE_MODULE_H_

namespace Framework::Core::DataStruct
{


    template<typename Type>
    class SingleLinkedListNode
    {
    public:

        Type                    value;
        SingleLinkedListNode*   next;


    public:
        SingleLinkedListNode() : value{}, next{ nullptr } {}

        SingleLinkedListNode(Type& v, SingleLinkedListNode* n) : value{ v }, next{ n } {}

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


        void InsertNext(SingleLinkedListNode* newNode)
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

        void DeleteNext()
        {
            delete UnlinkNext();
        }

    };


    template<typename Type>
    class SingleLinkedList
    {
    public:

        SingleLinkedListNode<Type>* head;


        void InsertHead(SingleLinkedListNode<Type>* newNode)
        {
            newNode->next   = head;
            head            = newNode;
        }

        SingleLinkedListNode<Type>* UnlinkHead()
        {

            if (head != nullptr)
            {
                SingleLinkedListNode<Type>* result{ head };
                head = head->next;
                return result;
            }

            return nullptr;

        }

        void DeleteHead()
        {
            delete UnlinkHead();
        }

        
    };

}

#endif