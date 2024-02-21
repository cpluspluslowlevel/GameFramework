#include "pch.h"
#include "HashTable.h"

namespace Framework::Core::DataStruct::Container
{

    UInt32 HashFunctionInt8(const Int8& key)
    {
        return HashFunctionUInt64(abs(key));
    }

    UInt32 HashFunctionInt16(const Int16& key)
    {
        return HashFunctionUInt64(abs(key));
    }

    UInt32 HashFunctionInt32(const Int32& key)
    {
        return HashFunctionUInt64(abs(key));
    }

    UInt32 HashFunctionInt64(const Int64& key)
    {
        return HashFunctionUInt64(abs(key));
    }

    UInt32 HashFunctionUInt8(const UInt8& key)
    {
        return HashFunctionUInt64(key);
    }

    UInt32 HashFunctionUInt16(const UInt16& key)
    {
        return HashFunctionUInt64(key);
    }

    UInt32 HashFunctionUInt32(const UInt32& key)
    {
        return HashFunctionUInt64(key);
    }

    UInt32 HashFunctionUInt64(const UInt64& key)
    {
        return UInt32(key % DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY);      //모듈러 연산 후 UInt32 범위 안으로 들어가기에 숫자가 짤리는 일은 일어나지 않습니다.
    }

    UInt32 HashFunctionMultibyte(const Multibyte*const& key)
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

    UInt32 HashFunctionUnicode(const Unicode*const& key)
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
        return HashFunctionMultibyte(key.c_str());
    }

    UInt32 HashFunctionString(const std::wstring& key)
    {
        return HashFunctionUnicode(key.c_str());
    }

}