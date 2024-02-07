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


        void LinkNext(SingleLinkedListNode* newNode)
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