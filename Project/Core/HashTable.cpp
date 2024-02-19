#include "pch.h"
#include "HashTable.h"

namespace Framework::Core::DataStruct::Container
{

    UInt32 HashFunction(const UInt32& key)
    {
        return key % DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY;
    }

}