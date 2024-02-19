#include "pch.h"
#include "HashTable.h"

namespace Framework::Core::DataStruct::Container
{

    UInt32 HashFunction(const UInt32& key)
    {
        return key % DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY;
    }

    UInt32 HashFunctionString(const Multibyte*& key)
    {

        static UInt64 MULTIPLIER{ 31 };

        UInt64 hash{ 0 };
        const Multibyte* p{ key };
        while(*p != '\0')
        {

            hash = hash * MULTIPLIER + *p;

            ++p;

        }

        return UInt32(hash % DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY);      //모듈러 연산 후 UInt32 범위 안으로 들어가기에 숫자가 짤리는 일은 일어나지 않습니다.
        
    }

    UInt32 HashFunctionString(const Unicode*& key)
    {

        static UInt64 MULTIPLIER{ 31 };

        UInt64 hash{ 0 };
        const Unicode* p{ key };
        while (*p != '\0')
        {

            hash = hash * MULTIPLIER + *p;

            ++p;

        }

        return UInt32(hash % DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY);      //모듈러 연산 후 UInt32 범위 안으로 들어가기에 숫자가 짤리는 일은 일어나지 않습니다.

    }

    UInt32 HashFunctionString(const std::string& key)
    {
        return HashFunctionString(key.c_str());
    }

    UInt32 HashFunctionString(const std::wstring& key)
    {
        return HashFunctionString(key.c_str());
    }

}