#include "pch.h"
#include "LinkedListTest.h"

int main()
{


    if (Framework::TestConsole::DataStruct::LinkedList::TestSingleLinkedList() != 0)
    {
        return -1;
    }
    std::cout << std::endl << std::endl << std::endl;

    if (Framework::TestConsole::DataStruct::LinkedList::TestDoubleLinkedList() != 0)
    {
        return -1;
    }
    std::cout << std::endl << std::endl << std::endl;

    return 0;

}