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

        return UInt32(hash % DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY);      //��ⷯ ���� �� UInt32 ���� ������ ���⿡ ���ڰ� ©���� ���� �Ͼ�� �ʽ��ϴ�.
        
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

        return UInt32(hash % DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY);      //��ⷯ ���� �� UInt32 ���� ������ ���⿡ ���ڰ� ©���� ���� �Ͼ�� �ʽ��ϴ�.

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