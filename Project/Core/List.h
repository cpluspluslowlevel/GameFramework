#ifndef _FRAMEWORK_CORE_LIST_H_
#define _FRAMEWORK_CORE_LIST_H_

#include "LinkedList.h"

namespace Framework::Core::DataStruct::Container
{

    /// <summary>
    /// 데이터 리스트를 다루는 컨테이너입니다.
    /// </summary>
    /// <typeparam name="Type">컨테이너를 구성하는 요소의 타입</typeparam>
    template<typename Type>
    class List
    {
    public:

        using ElementType   = Type;
        using NodeType      = LinkedList::DoubleLinkedListNode<ElementType>;

        List() : m_head{ nullptr }, m_tail{ nullptr } {}
        List(const std::initializer_list<int>& list) : m_head{ nullptr }, m_tail{ nullptr }
        {

            if (list.size() != 0)
            {

                auto iter{ list.begin() };

                //첫번째 요소는 따로 추가합니다.
                m_head = m_tail = new NodeType{ *iter };
                ++iter;

                //나머지 요소를 추가합니다.
                while (iter != list.end())
                {

                    m_tail->next = new NodeType{ *iter };
                    m_tail->next->prev = m_tail;
                    m_tail = m_tail->next;

                    iter = ++iter;

                }

            }

            

        }
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

        List& operator=(const List& lvalue)
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

        /// <summary>
        /// 처음 요소를 추가합니다.
        /// </summary>
        /// <param name="value">추가할 원소의 값</param>
        void InsertFirst(const ElementType& value)
        {

            if (IsEmpty())
            {
                m_head = m_tail = new NodeType{ value };
            }
            else
            {

                m_head->prev = new NodeType{ value };
                m_head->prev->next = m_head;
                m_head = m_head->prev;

            }

        }

        /// <summary>
        /// 처음 요소를 추가합니다.
        /// </summary>
        /// <param name="list">추가할 원소 리스트. 리스트의 순서대로 추가됩니다.</param>
        void InsertFirst(const std::initializer_list<ElementType>& list)
        {

            auto iter{ list.begin() };

            if (IsEmpty())
            {
                m_head = m_tail = new NodeType{ *iter };
                ++iter;
            }

            while (iter != list.end())
            {

                m_head->prev = new NodeType{ *iter };
                m_head->prev->next = m_head;
                m_head = m_head->prev;

                ++iter;

            }

        }

        /// <summary>
        /// 마지막 요소를 추가합니다.
        /// </summary>
        /// <param name="value">추가할 요소의 값</param>
        void InsertLast(const ElementType& value)
        {

            if (IsEmpty())
            {
                m_head = m_tail = new NodeType{ value };
            }
            else
            {

                m_tail->next = new NodeType{ value };
                m_tail->next->prev = m_tail;
                m_tail = m_tail->next;

            }
            
        }

        /// <summary>
        /// 마지막 요소를 추가합니다.
        /// </summary>
        /// <param name="list">추가할 원소 리스트. 리스트의 순서대로 추가됩니다.</param>
        void InsertLast(const std::initializer_list<ElementType>& list)
        {

            auto iter{ list.begin() };

            if (IsEmpty())
            {
                m_head = m_tail = new NodeType{ *iter };
                ++iter;
            }

            while (iter != list.end())
            {

                m_tail->next = new NodeType{ *iter };
                m_tail->next->prev = m_head;
                m_tail = m_tail->next;

                ++iter;

            }

        }


        /// <summary>
        /// 처음 원소를 삭제합니다.
        /// </summary>
        void DeleteFirst()
        {

            if (!IsEmpty())
            {

                auto headTemp{ m_head };

                //원소가 하나만 있을 때 예외 처리합니다.
                if (m_head == m_tail)       //IsEmpty()가 false인 상황에서 둘이 nullptr일리는 없습니다.
                {
                    m_head = m_tail = nullptr;
                }
                else
                {
                    m_head          = m_head->next;
                    m_head->prev    = nullptr;
                }

                delete headTemp;

            }
            
        }

        /// <summary>
        /// 마지막 원소를 삭제합니다.
        /// </summary>
        void DeleteLast()
        {

            if (!IsEmpty())
            {

                auto tailTemp{ m_tail };

                //원소가 하나만 있을 때 예외 처리합니다.
                if (m_head == m_tail)       //IsEmpty()가 false인 상황에서 둘이 nullptr일리는 없습니다.
                {
                    m_head = m_tail = nullptr;
                }
                else
                {
                    m_tail          = m_tail->prev;
                    m_tail->next    = nullptr;
                }
                
                delete tailTemp;

            }

        }

        /// <summary>
        /// 원소를 검색해 삭제합니다.
        /// 중복된 값이 있을 경우 먼저 발견된 원소를 삭제합니다.
        /// 머리부터 꼬리까지 순차적으로 탐색합니다.
        /// </summary>
        /// <param name="value">삭제할 원소의 값</param>
        /// <returns>요소를 삭제했으면 true, 아니면 false</returns>
        bool Delete(const ElementType& value)
        {

            //없는 요소를 삭제하려 할 경우 false를 리턴합니다.
            auto searchNode{ LinkedList::SearchNodeNext(m_head, value) };
            if (searchNode == nullptr)
            {
                return false;
            }

            if (m_head == m_tail)           //원소가 하나인 경우 m_head와 m_tail이 모두 변해야 합니다.
            {
                m_head = m_tail = nullptr;
            }
            else                            //원소가 두개 이상인 경우
            {

                if (searchNode == m_head)       //첫 요소를 삭제할 경우 m_head가 변해야 합니다.
                {
                    m_head = m_head->next;
                    m_head->prev = nullptr;
                }
                else if (searchNode == m_tail)  //마지막 요소를 삭제할 경우 m_tail이 변해야 합니다.
                {
                    m_tail = m_tail->prev;
                    m_tail->next = nullptr;
                }
                else
                {
                    searchNode->UnlinkSelf();
                }


            }

            delete searchNode;

            return true;

        }

        /// <summary>
        /// 원소를 검색해 삭제합니다.
        /// 중복된 값이 있을 경우 먼저 발견된 원소를 삭제합니다.
        /// 머리부터 꼬리까지 순차적으로 탐색합니다.
        /// </summary>
        /// <param name="function">원소를 삭제할지 테스트할 함수</param>
        /// <returns>요소를 삭제했으면 true, 아니면 false</returns>
        bool Delete(std::function<bool(const ElementType&)> function)
        {

            //없는 요소를 삭제하려 할 경우 false를 리턴합니다.
            auto searchNode{ LinkedList::SearchNodeNext(m_head, function) };
            if (searchNode == nullptr)
            {
                return false;
            }

            if (m_head == m_tail)           //원소가 하나인 경우 m_head와 m_tail이 모두 변해야 합니다.
            {
                m_head = m_tail = nullptr;
            }
            else                            //원소가 두개 이상인 경우
            {

                if (searchNode == m_head)       //첫 요소를 삭제할 경우 m_head가 변해야 합니다.
                {
                    m_head = m_head->next;
                    m_head->prev = nullptr;
                }
                else if (searchNode == m_tail)  //마지막 요소를 삭제할 경우 m_tail이 변해야 합니다.
                {
                    m_tail = m_tail->prev;
                    m_tail->next = nullptr;
                }
                else
                {
                    searchNode->UnlinkSelf();
                }


            }

            delete searchNode;

            return true;

        }

        NodeType* Search(const ElementType& value)
        {
            return LinkedList::SearchNodeNext(m_head, value);
        }

        const NodeType* Search(const ElementType& value) const
        {
            return LinkedList::SearchNodeNext(m_head, value);
        }

        NodeType* Search(std::function<bool(const ElementType&)> function)
        {
            return LinkedList::SearchNodeNext(m_head, function);
        }

        const NodeType* Search(std::function<bool(const ElementType&)> function) const
        {
            return LinkedList::SearchNodeNext(m_head, function);
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