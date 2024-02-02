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
            rvalue.next = nullptr;      //value�� ���ſ� ������ ���� �ֱ� ������ ������ ���� rvalue.value�� �ʱ�ȭ ���� �ʽ��ϴ�.
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

            rvalue.next = nullptr;      //value�� ���ſ� ������ ���� �ֱ� ������ ������ ���� rvalue.value�� �ʱ�ȭ ���� �ʽ��ϴ�.

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

            //�̹� �ڿ� � ��尡 �ִٸ� ���ο� ���(�Ǵ� ����Ʈ)�� �ڿ� �ٿ��ݴϴ�.
            //��尡 ����� ����Ʈ�̸� ����Ʈ ��ü�� �ٽ��ϴ�.
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