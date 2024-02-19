#include "pch.h"
#include "HashTableTest.h"

#include "../Core/HashTable.h"


namespace Framework::TestConsole::DataStruct::Container
{

    using namespace Framework::Core::DataStruct::Container;
    using namespace Framework::Core::DataStruct::LinkedList;

    using Pair = Framework::Core::PAIR<UInt32, UInt32>;

    constexpr UInt32 CONSTRUCTOR{ 0 };
    constexpr UInt32 OPERATOR{ 1 };
    constexpr UInt32 INSERT_ELEMENT{ 2 };
    constexpr UInt32 DELETE_ELEMENT{ 3 };
    constexpr UInt32 SEARCH_ELEMENT{ 4 };
    constexpr UInt32 EXIT{ 5 };

    template<typename KeyType, typename ValueType>
    void PrintHashTable(std::string_view name, std::string_view message, const Framework::Core::DataStruct::Container::HashTable<KeyType, ValueType>& hashTable, bool isClear = true, bool isContinuePrompt = true)
    {

        if (isClear)
        {
            system("cls");
        }

        std::cout << "--------------------------------------------------------------------" << std::endl;
        for (UInt32 i = 0; i < Framework::Core::DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY; ++i)
        {

            std::cout << "Container" << i << ": ";

            auto node{ hashTable.GetContainer(i).GetHeadNode() };
            while (node != nullptr)
            {

                std::cout << "[" << node->value.first << ", " << node->value.second << "]" << ", ";

                node = node->next;

            }
            std::cout << std::endl;

        }
        std::cout << "Size: " << hashTable.GetSize() << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Message: " << message << std::endl;

        if (isContinuePrompt)
        {
            std::cout << "input any key continue" << std::endl;
            std::string temp;
            std::cin >> temp;
        }

    }

    void Constructor();
    void Operator();
    void Insert();
    void Delete();
    void Search();

    int TestHashTable()
    {

        int select{};
        do
        {

            std::cout   << "Select test" << std::endl
                        << "(0: Constructor, 1: Operator, 2: Insert, 3: Delete, 4: Find, 5: Exit)" << std::endl
                        << "Select: ";
            std::cin >> select;
            //std::cout << "cin.good(): " << std::cin.good() << std::endl;
            //std::cout << "cin.fail(): " << std::cin.fail() << std::endl;
            //std::cout << "cin.bad(): " << std::cin.bad() << std::endl;
            //std::cout << "cin.eof(): " << std::cin.eof() << std::endl;

            if (!std::cin.good())
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input" << std::endl;
            }
            else
            {

                switch (select)
                {
                case CONSTRUCTOR:
                    Constructor();
                    break;
                case OPERATOR:
                    Operator();
                    break;
                case INSERT_ELEMENT:
                    Insert();
                    break;
                case DELETE_ELEMENT:
                    Delete();
                    break;
                case SEARCH_ELEMENT:
                    Search();
                    break;
                case EXIT:
                    break;
                default:
                    std::cout << "Invalid input" << std::endl;
                }

            }

            

        } while (select != EXIT);


        std::cout << "------------------------------------------------------------------------" << std::endl;


        return 0;

    }

    void Constructor()
    {

        HashTable<UInt32, UInt32> constructor0{ HashFunction };
        HashTable<UInt32, UInt32> constructor1{ HashFunction };

        constructor0.Insert(Pair{ 10, 10 });
        constructor0.Insert(Pair{ 20, 20 });
        constructor0.Insert(Pair{ 30, 30 });

        constructor1.Insert({ { 40, 40 }, { 50, 50 }, { 60, 60 } });

        PrintHashTable("constructorTest0", "Default constructor, Insert 10->20->30", constructor0);
        PrintHashTable("constructorTest1", "Default constructor, Insert 40->50->60", constructor1);

        HashTable<UInt32, UInt32> constructor2{ constructor0 };
        HashTable<UInt32, UInt32> constructor3{ std::move(constructor1) };

        PrintHashTable("constructorTest2", "Copy constructor(constructor0)",    constructor2);
        PrintHashTable("constructorTest0", "After copy",                        constructor0);
        PrintHashTable("constructorTest3", "Move constructor(constructor1)",    constructor3);
        PrintHashTable("constructorTest1", "After moved",                       constructor1);
        
        constructor0.Insert({ { 70, 70 }, { 80, 80 } });
        constructor1.Insert({ { 90, 90 }, { 100, 100 } });
        PrintHashTable("constructorTest0", "Modify, insert 70->80",                      constructor0);
        PrintHashTable("constructorTest1", "Modify, insert 90->100",                     constructor1);
        PrintHashTable("constructorTest2", "Copy 0 before modify",                       constructor2);
        PrintHashTable("constructorTest3", "Move 1 before modify",                       constructor3);

        system("cls");

    }

    void Operator()
    {

        HashTable<UInt32, UInt32> operator0{ HashFunction };
        HashTable<UInt32, UInt32> operator1{ HashFunction };

        operator0.Insert({ { 10, 10 }, { 20, 20 }, { 30, 30 } });
        operator1.Insert({ { 40, 40 }, { 50, 50 }, { 60, 60 } });

        PrintHashTable("operator0", "Insert 10->20->30", operator0);
        PrintHashTable("operator1", "Insert 40->50->60", operator1);

        HashTable<UInt32, UInt32> operator2{ HashFunction };
        HashTable<UInt32, UInt32> operator3{ HashFunction };
        operator2 = operator0;
        operator3 = std::move(operator1);

        PrintHashTable("operator2", "Copy operator(operator0)",     operator2);
        PrintHashTable("operator0", "After copy",                   operator0);
        PrintHashTable("operator3", "Move operator(operator1)",     operator3);
        PrintHashTable("operator1", "After moved",                  operator1);
        
        operator0.Insert({ { 70, 70 }, { 80, 80 } });
        operator1.Insert({ { 90, 90 }, { 100, 100 } });
        PrintHashTable("operator0", "Modify, insert 70->80",    operator0);
        PrintHashTable("operator1", "Modify, insert 90->100",   operator1);
        PrintHashTable("operator2", "Copy 0 before modify",     operator2);
        PrintHashTable("operator3", "Move 1 before modify",     operator3);

        system("cls");

    }

    void Insert()
    {

        HashTable<UInt32, UInt32> insertTable{ HashFunction };

        insertTable.Insert(10, 10);
        PrintHashTable("insertTable", "Insert(key, value)",                     insertTable);

        insertTable.Insert(Pair{ 20, 20 });
        PrintHashTable("insertTable", "Insert(Pair)",                           insertTable);

        insertTable.Insert({ { 30, 30 }, { 40, 40 }, { 50, 50 } });
        PrintHashTable("insertTable", "Insert(init-list{Pair, Pair, Pair})",    insertTable);

        for (int i = 0; i <= 100; ++i)
        {
            insertTable.Insert(i, i);
        }
        PrintHashTable("insertTable", "Insert 0~100)", insertTable);

        system("cls");



    }

    void Delete()
    {

        HashTable<UInt32, UInt32> deleteTable{ HashFunction };
        for (int i = 0; i <= 100; ++i)
        {
            deleteTable.Insert(i, i);
        }
        PrintHashTable("deleteTable", "Insert 0~100)", deleteTable);

        for (int i = 0; i <= 10; ++i)
        {
            deleteTable.Delete(100 - i);
        }
        PrintHashTable("deleteTable", "Delete 90~100)", deleteTable);

        for (int i = 0; i <= 10; ++i)
        {
            deleteTable.Delete(55 - i);
        }
        PrintHashTable("deleteTable", "Delete 45~55)", deleteTable);

        for (int i = 0; i <= 10; ++i)
        {
            deleteTable.Delete(10 - i);
        }
        PrintHashTable("deleteTable", "Delete 0~10)", deleteTable);

        system("cls");

    }

    void Search()
    {

        HashTable<UInt32, UInt32> searchTable{ HashFunction };
        for (int i = 0; i <= 100; ++i)
        {
            if (i % 2 == 0)
            {
                searchTable.Insert(i, i);
            }
        }
        PrintHashTable("searchTable", "Insert 0~100 even number)", searchTable);

        List<UInt32> notFoundList{};
        for (UInt32 i = 0; i <= 110; ++i)
        {

            auto searchNode{ searchTable.SearchNode(i) };
            if (searchNode != nullptr)
            {
                searchNode->value.second *= 10;
            }
            else
            {
                notFoundList.InsertLast(i);
            }

        }

        PrintHashTable("searchTable", "SearchNode 0~110, node value x10", searchTable, true, false);
        auto notFoundNode{ notFoundList.GetHeadNode() };
        while (notFoundNode != nullptr)
        {
            std::cout << notFoundNode->value << " is not found" << std::endl;
            notFoundNode = notFoundNode->next;
        }


        std::cout << "input any key continue" << std::endl;
        std::string temp;
        std::cin >> temp;

        system("cls");

    }

}