#include "pch.h"
#include "LinkedListTest.h"

int main()
{


    if (Framework::TestConsole::DataStruct::LinkedList::TestSingleLinkedList() != 0)
    {
        return -1;
    }

    return 0;

}