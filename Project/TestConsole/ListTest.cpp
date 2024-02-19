#include "pch.h"
#include "ListTest.h"

#include "../Core/List.h"

namespace Framework::TestConsole::DataStruct::Container
{

    template<typename Type>
    std::ostream& operator<<(std::ostream& os, const Framework::Core::DataStruct::Container::List<Type>& list)
    {

        if (list.IsEmpty())
        {
            return os;
        }

        //리스트 헤드의 Prev가 nullptr이 아닌 경우를 검출하기 위해 GetFirstNode로 검색해봅니다.
        auto node{ Framework::Core::DataStruct::LinkedList::GetFirstNode(list.GetHeadNode()) };
        while (node != nullptr)
        {

            std::cout << node->value << ", ";

            node = node->next;

        }

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
                std::cout << "[*" << loop->value << "*]";
            }
            else
            {
                std::cout << "[" << loop->value << "]";
            }

            loop = loop->next;

        }
        std::cout << std::endl;

    }

    int TestList()
    {

        using namespace Framework::Core::DataStruct::Container;


        //생성
        List<int> constructor0{};
        List<int> constructor1{ 40, 50, 60 };
        constructor0.InsertLast(10);
        constructor0.InsertLast(20);
        constructor0.InsertLast(30);

        List<int> constructor2{ constructor0 };
        List<int> constructor3{ std::move(constructor1) };

        std::cout << "Constructor test" << std::endl;
        std::cout << "constructor0(Default, 10->20->30): "      << constructor0 << std::endl;
        std::cout << "constructor1(Init-List, 40->50->60): "    << constructor1 << std::endl;
        std::cout << "constructor2(Copy 0, 10->20->30): "       << constructor2 << std::endl;
        std::cout << "constructor3(Move 1, 40->50->60): "       << constructor3 << std::endl;

        std::cout << std::endl;

        constructor0.InsertLast({ 70, 80 });
        constructor1.InsertLast({ 90, 100 });
        std::cout << "constructor0(Modify, 70->80): "       << constructor0 << std::endl;
        std::cout << "constructor1(Modify, 90->100): "      << constructor1 << std::endl;
        std::cout << "constructor2(Copy 0 before modify): " << constructor2 << std::endl;
        std::cout << "constructor3(Move 1 before modify): " << constructor3 << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;

        //대입
        List<int> operator0{};
        List<int> operator1{};
        operator0.InsertLast(10);
        operator0.InsertLast(20);
        operator0.InsertLast(30);
        operator1.InsertLast(40);
        operator1.InsertLast(50);
        operator1.InsertLast(60);

        List<int> operator2{ operator0 };
        List<int> operator3{ std::move(operator1) };

        std::cout << "Operator test" << std::endl;
        std::cout << "operator0(Default, 10->20->30): "         << operator0 << std::endl;
        std::cout << "operator1(Default, Moved to operator3): " << operator1 << std::endl;
        std::cout << "operator2(Copy 0, 10->20->30): "          << operator2 << std::endl;
        std::cout << "operator3(Move 1, 40->50->60): "          << operator3 << std::endl;


        operator0.InsertLast(70);
        operator0.InsertLast(80);
        std::cout << "operator0(Modify, 10->20->30->70->80): "      << operator0 << std::endl;
        std::cout << "operator2(Copy before modify, 10->20->30): "  << operator2 << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;

        //삽입
        List<int> insertFirst{};
        insertFirst.InsertFirst(10);
        insertFirst.InsertFirst(20);
        insertFirst.InsertFirst(30);

        List<int> insertFirstInitializerList{};
        insertFirstInitializerList.InsertFirst({ 10,20,30 });

        List<int> insertLast{};
        insertLast.InsertLast(10);
        insertLast.InsertLast(20);
        insertLast.InsertLast(30);

        List<int> insertLastInitializerList{};
        insertLastInitializerList.InsertLast({ 10,20,30 });

        List<int> insertBidirection{};
        insertBidirection.InsertFirst(10);
        insertBidirection.InsertLast(20);
        insertBidirection.InsertFirst(30);
        insertBidirection.InsertLast(40);
        insertBidirection.InsertFirst(50);

        List<int> insertBidirectionInitializerList{};
        insertBidirectionInitializerList.InsertFirst({ 50, 40 });
        insertBidirectionInitializerList.InsertLast({ 60, 70 });
        insertBidirectionInitializerList.InsertFirst({ 30, 20 });
        insertBidirectionInitializerList.InsertLast({ 80, 90 });
        insertBidirectionInitializerList.InsertFirst({ 10 });
        insertBidirectionInitializerList.InsertLast({ 100 });

        std::cout << "Insert test" << std::endl;
        std::cout << "insertFirst(10->20->30): "                            << insertFirst << std::endl;
        std::cout << "insertFirstInitializerList(10->20->30): "             << insertFirstInitializerList << std::endl;
        std::cout << "insertLast(10->20->30): "                             << insertLast << std::endl;
        std::cout << "insertLastInitializerList(10->20->30): "              << insertLastInitializerList << std::endl;
        std::cout << "insertBidirection(10->...->50): "                     << insertBidirection << std::endl;
        std::cout << "insertBidirectionInitializerList(10, ..., 100): "     << insertBidirectionInitializerList << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;


        //삭제
        List<int> deleteFirst{};
        deleteFirst.InsertLast(10);
        deleteFirst.InsertLast(20);
        deleteFirst.InsertLast(30);

        std::cout << "Delete test" << std::endl;

        std::cout << "DeleteFirst: " << deleteFirst << std::endl;
        deleteFirst.DeleteFirst();
        deleteFirst.DeleteFirst();
        std::cout << "Delete first(10->20): " << deleteFirst << std::endl;
        deleteFirst.DeleteFirst();
        std::cout << "Delete first(30): " << deleteFirst << std::endl;


        List<int> deleteLast{};
        deleteLast.InsertLast(10);
        deleteLast.InsertLast(20);
        deleteLast.InsertLast(30);

        std::cout << "DeleteLast: " << deleteLast << std::endl;
        deleteLast.DeleteLast();
        deleteLast.DeleteLast();
        std::cout << "Delete last(30->20): " << deleteLast << std::endl;
        deleteLast.DeleteLast();
        std::cout << "Delete last(10): " << deleteLast << std::endl;


        //탐색
        List<int> search{};
        search.InsertLast(10);
        search.InsertLast(20);
        search.InsertLast(30);
        search.InsertLast(40);
        search.InsertLast(50);

        PrintList("Search(10): ", *search.Search(10));
        PrintList("Search(20): ", *search.Search(20));
        PrintList("Search(30): ", *search.Search(30));
        PrintList("Search(40): ", *search.Search(40));
        PrintList("Search(50): ", *search.Search(50));

        std::cout << std::endl;

        PrintList("Functional search(10): ", *search.Search([](const int& nodeValue){ return nodeValue == 10; }));
        PrintList("Functional search(20): ", *search.Search([](const int& nodeValue){ return nodeValue == 20; }));
        PrintList("Functional search(30): ", *search.Search([](const int& nodeValue){ return nodeValue == 30; }));
        PrintList("Functional search(40): ", *search.Search([](const int& nodeValue){ return nodeValue == 40; }));
        PrintList("Functional search(50): ", *search.Search([](const int& nodeValue){ return nodeValue == 50; }));

        return 0;

    }

}