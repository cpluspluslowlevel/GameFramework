#include "pch.h"
#include "LinkedListTest.h"

#include "../Core/LinkedList.h"

namespace Framework::TestConsole::DataStruct::LinkedList
{

    template<typename Type>
    std::ostream& operator<<(std::ostream& os, const Framework::Core::DataStruct::LinkedList::SingleLinkedListNode<Type>& node)
    {

        if (node.next != nullptr)
        {
            os << "Value: " << node.value << ", Next value: " << node.next->value;
        }
        else
        {
            os << "Value: " << node.value << ", Next value: None";
        }

        return os;

    }

    template<typename Type>
    void PrintList(std::string_view title, const Framework::Core::DataStruct::LinkedList::SingleLinkedListNode<Type>& node)
    {

        std::cout << title;

        auto loop{ &node };
        while (loop != nullptr)
        {

            std::cout << "[" << *loop << "]";
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
        SingleLinkedListNode<int> constructorTest2{ 20, &constructorTest0 };
        SingleLinkedListNode<int> constructorTest3{ constructorTest2 };
        SingleLinkedListNode<int> constructorTest4{ std::move(constructorTest2) };

        std::cout << "Constructor test" << std::endl;
        std::cout << "constructorTest0: " << constructorTest0 << std::endl;
        std::cout << "constructorTest1: " << constructorTest1 << std::endl;
        std::cout << "constructorTest2: " << constructorTest2 << std::endl;
        std::cout << "constructorTest3: " << constructorTest3 << std::endl;
        std::cout << "constructorTest4: " << constructorTest4 << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;

        //노드의 대입 연산자 재정의가 정상 작동 하는가
        SingleLinkedListNode<int> operatorTest0{ 10 };
        SingleLinkedListNode<int> operatorTest1{ 10, &operatorTest0 };
        SingleLinkedListNode<int> operatorTest2{ 20, &operatorTest0 };
        SingleLinkedListNode<int> operatorTest3{ 30 };
        SingleLinkedListNode<int> operatorTest4{ 40 };

        operatorTest3 = operatorTest1;
        operatorTest4 = std::move(operatorTest2);

        std::cout << "Operator test" << std::endl;
        std::cout << "operatorTest0: " << operatorTest0 << std::endl;
        std::cout << "operatorTest1: " << operatorTest1 << std::endl;
        std::cout << "operatorTest2: " << operatorTest2 << std::endl;
        std::cout << "operatorTest3(Copy operatorTest1): " << operatorTest3 << std::endl;
        std::cout << "operatorTest4(Move operatorTest2): " << operatorTest4 << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;

        //입력
        //중간 노드를 추가할 수 있는가
        //가장 앞에 노드를 추가할 수 있는가
        //가장 뒤에 노드를 추가할 수 있는가
        auto insertHead = new SingleLinkedListNode<int>{ 1000, nullptr };
        insertHead->LinkNext(new SingleLinkedListNode<int>{ 2000, nullptr });
        insertHead->next->LinkNext(new SingleLinkedListNode<int>{ 3000, nullptr });

        std::cout << "Insert test" << std::endl;
        
        PrintList("Base: ", *insertHead);
        
        insertHead->next->LinkNext(new SingleLinkedListNode<int>{ 4000, nullptr });
        PrintList("Middle insertion: ", *insertHead);

        insertHead = new SingleLinkedListNode<int>{ 5000, insertHead };
        PrintList("First insertion: ", *insertHead);

        LinkLastNode(insertHead, new SingleLinkedListNode<int>{ 6000, nullptr });
        PrintList("Back insertion: ", *insertHead);

        std::cout << "------------------------------------------------------------------------" << std::endl;

        //삭제
        //중간 노드를 삭제 할 수 있는가
        //가장 앞에 노드를 삭제 할 수 있는가
        //가장 뒤에 노드를 삭제 할 수 있는가
        auto deleteHead = new SingleLinkedListNode<int>{ 1000, nullptr };
        deleteHead->LinkNext(new SingleLinkedListNode<int>{ 2000, nullptr });
        deleteHead->next->LinkNext(new SingleLinkedListNode<int>{ 3000, nullptr });
        deleteHead->next->next->LinkNext(new SingleLinkedListNode<int>{ 4000, nullptr });

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
        auto findHead = new SingleLinkedListNode<int>{ 1000, nullptr };
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 2000, nullptr });
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 3000, nullptr });
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 4000, nullptr });
        LinkLastNode(findHead, new SingleLinkedListNode<int>{ 5000, nullptr });

        PrintList("Base: ", *findHead);
        PrintList("Find(3000): ", *SearchNode(findHead, 3000));
        PrintList("Find(1000): ", *SearchNode(findHead, 1000));
        PrintList("Find(5000): ", *SearchNode(findHead, 5000));
        
        std::cout << "------------------------------------------------------------------------" << std::endl;

        return 0;

    }


}