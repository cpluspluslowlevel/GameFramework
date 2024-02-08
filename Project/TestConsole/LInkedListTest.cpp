#include "pch.h"
#include "LinkedListTest.h"

#include "../Core/LinkedList.h"

//#define LINKEDLISTTEST_SHOW_LINKED_NODE_VALUE

namespace Framework::TestConsole::DataStruct::LinkedList
{

    template<typename Type>
    std::ostream& operator<<(std::ostream& os, const Framework::Core::DataStruct::LinkedList::SingleLinkedListNode<Type>& node)
    {

        os << "Value: " << node.value;

#ifdef LINKEDLISTTEST_SHOW_LINKED_NODE_VALUE
        if (node.next != nullptr)
        {
            os << ", Next value: " << node.next->value;
        }
        else
        {
            os << ", Next value: None";
        }
#endif

        return os;

    }

    template<typename Type>
    void PrintList(std::string_view title, const Framework::Core::DataStruct::LinkedList::SingleLinkedListNode<Type>& node)
    {

        std::cout << title;

        auto loop{ &node };
        while (loop != nullptr)
        {

            if (loop == &node)
            {
                std::cout << "[*" << *loop << "*]";
            }
            else
            {
                std::cout << "[" << *loop << "]";
            }

            loop = loop->next;

        }
        std::cout << std::endl;

    }

    int TestSingleLinkedList()
    {

        using namespace Framework::Core::DataStruct::LinkedList;

        //노드의 생성자가 정상 작동 하는가
        SingleLinkedListNode<int> constructorTest0{};
        SingleLinkedListNode<int> constructorTest1{ 10 };

        std::cout << "Constructor test" << std::endl;
        std::cout << "constructorTest0: " << constructorTest0 << std::endl;
        std::cout << "constructorTest1: " << constructorTest1 << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;


        //입력
        //중간 노드를 추가할 수 있는가
        //가장 앞에 노드를 추가할 수 있는가
        //가장 뒤에 노드를 추가할 수 있는가
        auto insertHead = new SingleLinkedListNode<int>{ 1000 };
        insertHead->LinkNext(new SingleLinkedListNode<int>{ 2000 });
        insertHead->next->LinkNext(new SingleLinkedListNode<int>{ 3000 });

        std::cout << "Insert test" << std::endl;
        
        PrintList("Base: ", *insertHead);
        
        insertHead->next->LinkNext(new SingleLinkedListNode<int>{ 4000 });
        PrintList("Middle insertion: ", *insertHead);

        insertHead = new SingleLinkedListNode<int>{ 5000 };
        PrintList("First insertion: ", *insertHead);

        LinkLastNode(insertHead, new SingleLinkedListNode<int>{ 6000 });
        PrintList("Back insertion: ", *insertHead);

        std::cout << "------------------------------------------------------------------------" << std::endl;


        //삭제
        //중간 노드를 삭제 할 수 있는가
        //가장 앞에 노드를 삭제 할 수 있는가
        //가장 뒤에 노드를 삭제 할 수 있는가
        auto deleteHead = new SingleLinkedListNode<int>{ 1000 };
        deleteHead->LinkNext(new SingleLinkedListNode<int>{ 2000 });
        deleteHead->next->LinkNext(new SingleLinkedListNode<int>{ 3000 });
        deleteHead->next->next->LinkNext(new SingleLinkedListNode<int>{ 4000 });

        std::cout << "Delete test" << std::endl;

        PrintList("Base: ", *deleteHead);

        delete deleteHead->next->UnlinkNext();
        PrintList("Middle delete: ", *deleteHead);

        auto deleteTemp{ deleteHead };
        deleteHead = deleteHead->next;
        delete deleteTemp;
        PrintList("First delete: ", *deleteHead);

        delete UnlinkLastNode(deleteHead);
        PrintList("Last delete", *deleteHead);

        std::cout << "------------------------------------------------------------------------" << std::endl;


        //탐색
        //특정 값을 갖는 노드를 찾을 수 있는가
        auto findHead = new SingleLinkedListNode<int>{ 1000 };
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 2000 });
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 3000 });
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 4000 });
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 5000 });

        std::cout << "Searching test" << std::endl;

        PrintList("Base: ", *findHead);
        PrintList("Search(3000): ", *SearchNode(findHead, 3000));
        PrintList("Search(1000): ", *SearchNode(findHead, 1000));
        PrintList("Search(5000): ", *SearchNode(findHead, 5000));
        
        std::cout << "------------------------------------------------------------------------" << std::endl;

        return 0;

    }





    template<typename Type>
    std::ostream& operator<<(std::ostream& os, const Framework::Core::DataStruct::LinkedList::DoubleLinkedListNode<Type>& node)
    {

        os << "Value: " << node.value;

#ifdef LINKEDLISTTEST_SHOW_LINKED_NODE_VALUE
        if (node.prev != nullptr)
        {
            os << ", Prev value: " << node.prev->value;
        }
        else
        {
            os << ", Prev value: None";
        }

        if (node.next != nullptr)
        {
            os << ", Next value: " << node.next->value;
        }
        else
        {
            os << ", Next value: None";
        }
#endif

        return os;

    }

    template<typename Type>
    void PrintList(std::string_view title, const Framework::Core::DataStruct::LinkedList::DoubleLinkedListNode<Type>& node)
    {

        std::cout << title;

        auto loop{ Framework::Core::DataStruct::LinkedList::GetFirstNode(&node) };
        while (loop != nullptr)
        {

            if (loop == &node)
            {
                std::cout << "[*" << *loop << "*]";
            }
            else
            {
                std::cout << "[" << *loop << "]";
            }

            loop = loop->next;

        }
        std::cout << std::endl;

    }

    int TestDoubleLinkedList()
    {

        using namespace Framework::Core::DataStruct::LinkedList;

        //노드의 생성자가 정상 작동 하는가
        DoubleLinkedListNode<int> constructorTest0{};
        DoubleLinkedListNode<int> constructorTest1{ 10 };
        DoubleLinkedListNode<int> constructorTest2{ 20 };

        std::cout << "Constructor test" << std::endl;
        std::cout << "constructorTest0: " << constructorTest0 << std::endl;
        std::cout << "constructorTest1: " << constructorTest1 << std::endl;
        std::cout << "constructorTest2: " << constructorTest2 << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;


        //입력
        //중간 노드를 추가할 수 있는가
        //가장 앞에 노드를 추가할 수 있는가
        //가장 뒤에 노드를 추가할 수 있는가
        auto insertCenter = new DoubleLinkedListNode<int>{ 4000 };

        std::cout << "Insert test" << std::endl;

        PrintList("Base: ", *insertCenter);

        LinkFirstNode(GetFirstNode(insertCenter), new DoubleLinkedListNode<int>{ 2000 });
        LinkFirstNode(insertCenter, new DoubleLinkedListNode<int>{ 1000 });
        PrintList("First insertion(2000->1000): ", *insertCenter);

        LinkLastNode(GetLastNode(insertCenter), new DoubleLinkedListNode<int>{ 6000 });
        LinkLastNode(insertCenter, new DoubleLinkedListNode<int>{ 7000 });
        PrintList("Back insertion(6000->7000): ", *insertCenter);

        insertCenter->LinkPrev(new DoubleLinkedListNode<int>{ 3000 });
        insertCenter->LinkNext(new DoubleLinkedListNode<int>{ 5000 });
        PrintList("Middle insertion(3000->5000): ", *insertCenter);

        std::cout << "------------------------------------------------------------------------" << std::endl;


        //삭제
        //중간 노드를 삭제 할 수 있는가
        //가장 앞에 노드를 삭제 할 수 있는가
        //가장 뒤에 노드를 삭제 할 수 있는가
        auto deleteHead = new DoubleLinkedListNode<int>{ 1000 };
        LinkLastNode(deleteHead, new DoubleLinkedListNode<int>{ 2000 });
        LinkLastNode(deleteHead, new DoubleLinkedListNode<int>{ 3000 });
        LinkLastNode(deleteHead, new DoubleLinkedListNode<int>{ 4000 });
        LinkLastNode(deleteHead, new DoubleLinkedListNode<int>{ 5000 });
        LinkLastNode(deleteHead, new DoubleLinkedListNode<int>{ 6000 });
        LinkLastNode(deleteHead, new DoubleLinkedListNode<int>{ 7000 });
        auto deleteCenter{ deleteHead->next->next->next }; //value 4000 node

        std::cout << "Delete test" << std::endl;

        PrintList("Base: ", *deleteCenter);

        delete deleteCenter->UnlinkPrev();
        delete deleteCenter->UnlinkNext();
        PrintList("Middle delete(3000->5000): ", *deleteCenter);

        delete UnlinkFirstNode(GetFirstNode(deleteCenter));
        delete UnlinkFirstNode(deleteCenter);
        PrintList("First delete(1000->2000): ", *deleteCenter);

        delete UnlinkLastNode(GetLastNode(deleteCenter));
        delete UnlinkLastNode(deleteCenter);
        PrintList("Last delete(7000->6000): ", *deleteCenter);

        PrintList("First delete(Single node): ", *UnlinkFirstNode(deleteCenter));
        PrintList("Last delete(Single node): ", *UnlinkLastNode(deleteCenter));

        std::cout << "------------------------------------------------------------------------" << std::endl;


        //탐색
        //특정 값을 갖는 노드를 찾을 수 있는가
        auto findHead = new DoubleLinkedListNode<int>{ 1000 };
        LinkLastNode(findHead, new DoubleLinkedListNode<int>{ 2000 });
        LinkLastNode(findHead, new DoubleLinkedListNode<int>{ 3000 });
        LinkLastNode(findHead, new DoubleLinkedListNode<int>{ 4000 });
        LinkLastNode(findHead, new DoubleLinkedListNode<int>{ 5000 });
        LinkLastNode(findHead, new DoubleLinkedListNode<int>{ 6000 });
        LinkLastNode(findHead, new DoubleLinkedListNode<int>{ 7000 });
        auto findCenter{ findHead->next->next->next };

        std::cout << "Searching test" << std::endl;

        PrintList("Base: ", *findCenter);
        PrintList("Prev Searching(2000): ",     *SearchNodePrev(findCenter, 2000));
        PrintList("Prev Searching(1000): ",     *SearchNodePrev(findCenter, 1000));
        PrintList("Prev Searching(4000): ",     *SearchNodePrev(findCenter, 4000));
        PrintList("Last Searching(6000): ",     *SearchNodeNext(findCenter, 6000));
        PrintList("Last Searching(7000): ",     *SearchNodeNext(findCenter, 7000));
        PrintList("Last Searching(4000): ",     *SearchNodeNext(findCenter, 4000));
        
        std::cout << "------------------------------------------------------------------------" << std::endl;

        return 0;

    }


}