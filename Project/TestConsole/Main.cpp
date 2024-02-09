#include "pch.h"
#include "LinkedListTest.h"
#include "ListTest.h"

int main()
{


    std::cout << "SingleLinkedList--------------------------------------------------------" << std::endl;
    if (Framework::TestConsole::DataStruct::LinkedList::TestSingleLinkedList() != 0)
    {
        return -1;
    }
    std::cout << std::endl << std::endl << std::endl;


    std::cout << "DoubleLinkedList--------------------------------------------------------" << std::endl;
    if (Framework::TestConsole::DataStruct::LinkedList::TestDoubleLinkedList() != 0)
    {
        return -1;
    }
    std::cout << std::endl << std::endl << std::endl;


    std::cout << "ListTest----------------------------------------------------------------" << std::endl;
    if (Framework::TestConsole::DataStruct::Container::TestList() != 0)
    {
        return -1;
    }
    std::cout << std::endl << std::endl << std::endl;


    return 0;

}