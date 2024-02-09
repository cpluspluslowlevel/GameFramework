#ifndef _FRAMEWORK_CORE_LIST_H_
#define _FRAMEWORK_CORE_LIST_H_

#include "LinkedList.h"

namespace Framework::Core::DataStruct::Container
{

    template<typename Type>
    class List
    {
    public:

        using ElementType   = Type;
        using NodeType      = LinkedList::DoubleLinkedListNode<ElementType>;

        List() : m_head{ nullptr }, m_tail{ nullptr } {}
        List(const List& lvalue) : m_head{ nullptr }, m_tail{ nullptr }
        {

            if (!lvalue.IsEmpty())
            {

                //InsertLast함수를 반복적으로 호출하면 IsEmpty()를 반복적으로 검사하기에 삽입 코드를 직접 작성했습니다.

                m_head = m_tail = new NodeType{ lvalue.m_head->value };

                auto loop{ lvalue.m_head->next };
                while (loop != nullptr)
                {

                    m_tail->next = new NodeType{ loop->value };
                    m_tail->next->prev = m_tail;
                    m_tail = m_tail->next;

                    loop = loop->next;

                }

            }

        }

        List(List&& rvalue) noexcept : m_head{ rvalue.m_head }, m_tail{ rvalue.m_tail }
        {
            rvalue.m_head = rvalue.m_tail = nullptr;
        }

        ~List() noexcept
        {

            NodeType*   temp{ nullptr };
            auto        loop{ m_head };
            while (loop != nullptr)
            {

                temp = loop;
                loop = loop->next;

                delete temp;

            }

        }

        List& operator=(const List&& lvalue)
        {

            if (!lvalue.IsEmpty())
            {

                //InsertLast함수를 반복적으로 호출하면 IsEmpty()를 반복적으로 검사하기에 삽입 코드를 직접 작성했습니다.

                m_head = m_tail = new NodeType{ lvalue.m_head->value };

                auto loop{ lvalue.m_head->next };
                while (loop != nullptr)
                {

                    m_tail->next = new NodeType{ loop->value };
                    m_tail->next->prev = m_tail;
                    m_tail = m_tail->next;

                    loop = loop->next;

                }

            }
            else
            {
                m_head = m_tail = nullptr;
            }

            return *this;

        }

        List& operator=(List&& rvalue) noexcept
        {

            m_head = rvalue.m_head;
            m_tail = rvalue.m_tail;

            rvalue.m_head = rvalue.m_tail = nullptr;

            return *this;

        }

        void InsertFirst(const ElementType& value)
        {

            if (IsEmpty())
            {
                m_head = m_tail = new NodeType{ value };
            }
            else
            {

                m_head->LinkPrev(new NodeType{ value });
                m_head = m_head->prev;

            }

        }

        void InsertLast(const ElementType& value)
        {

            if (IsEmpty())
            {
                m_head = m_tail = new NodeType{ value };
            }
            else
            {

                m_tail->LinkNext(new NodeType{ value });
                m_tail = m_tail->next;

            }
            
        }


        void DeleteFirst()
        {

            if (!IsEmpty())
            {
                auto headTemp{ m_head };
                m_head = m_head->next;
                delete headTemp;
            }
            
        }

        void DeleteLast()
        {

            if (!IsEmpty())
            {
                auto tailTemp{ m_tail };
                m_tail = m_tail->prev;
                delete tailTemp;
            }

        }

        NodeType* Search(const ElementType& value)
        {
            return LinkedList::SearchNodeNext(m_head, value);
        }

        const NodeType* Search(const ElementType& value) const
        {
            return LinkedList::SearchNodeNext(m_head, value);
        }


        bool IsEmpty() const
        {
            return m_head == nullptr;
        }

        //Getter

        NodeType* GetHeadNode()
        {
            return m_head;
        }

        const NodeType* GetHeadNode() const
        {
            return m_head;
        }


        NodeType* GetTailNode()
        {
            return m_tail;
        }

        const NodeType* GetTailNode() const
        {
            return m_tail;
        }

    private:

        
        NodeType* m_head;
        NodeType* m_tail;

        

    };

}

#endif