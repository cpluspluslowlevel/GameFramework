#ifndef _FRAMEWORK_CORE_HASHTABLE_H_
#define _FRAMEWORK_CORE_HASHTABLE_H_

#include "List.h"

namespace Framework::Core::DataStruct::Container
{

    enum class EHashTableInsertResult
    {

        Success,
        DuplicateKey

    };

    template<typename _KeyType, typename _ValueType>
    class HashTable
    {
    public:

        using KeyType               = _KeyType;
        using ElementType           = _ValueType;
        using PairType              = PAIR<KeyType, ElementType>;
        using ListType              = List<PairType>;
        using HashFunctionType      = UInt32 (*)(const KeyType&);

    public:
        HashTable(HashFunctionType hashFunction) : m_hashFunction{ hashFunction }, m_container{}, m_size{ 0LL } {}

        HashTable(const HashTable& lvalue) : m_hashFunction{ lvalue.m_hashFunction }, m_container{}, m_size{ lvalue.m_size }
        {
            for (UInt64 i = 0; i < DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY; ++i)
            {
                m_container[i] = lvalue.m_container[i];
            }
        }

        HashTable(HashTable&& rvalue) noexcept : m_hashFunction{ rvalue.m_hashFunction }, m_container{}, m_size{ rvalue.m_size }
        {
            for (UInt64 i = 0; i < DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY; ++i)
            {
                m_container[i] = std::move(rvalue.m_container[i]);
            }
            rvalue.m_size = 0;
        }

        HashTable& operator=(const HashTable& lvalue)
        {

            m_hashFunction  = lvalue.m_hashFunction;
            m_size          = lvalue.m_size;

            for (UInt64 i = 0; i < DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY; ++i)
            {
                m_container[i] = lvalue.m_container[i];
            }

            return *this;

        }
        
        HashTable& operator=(HashTable&& rvalue) noexcept
        {

            m_hashFunction  = std::move(rvalue.m_hashFunction);
            m_size          = rvalue.m_size;

            for (UInt64 i = 0; i < DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY; ++i)
            {
                m_container[i] = std::move(rvalue.m_container[i]);
            }

            rvalue.m_size = 0;

            return *this;

        }

        ~HashTable() noexcept = default;


        EHashTableInsertResult Insert(const PairType& pair)
        {

            auto searchFunction{ [&](const PairType& nodePair) { return nodePair.first == pair.first; } };

            UInt32 hash{ m_hashFunction(pair.first) };
            if (m_container[hash].Search(searchFunction) != nullptr)
            {
                return EHashTableInsertResult::DuplicateKey;
            }
            
            m_container[hash].InsertLast(pair);
            ++m_size;

            return EHashTableInsertResult::Success;

        }

        EHashTableInsertResult Insert(const KeyType& key, const ElementType& value)
        {
            return Insert({ key, value });
        }

        EHashTableInsertResult Insert(const std::initializer_list<PairType>& list)
        {

            for (auto& pair : list)
            {
                Insert(pair);
            }

            return EHashTableInsertResult::Success;

        }

        void Delete(const KeyType& key)
        {
            m_container[m_hashFunction(key)].Delete([&](const PairType& nodePair) { return nodePair.first == key; });
        }

        ListType::NodeType* SearchNode(const KeyType& key)
        {

            return m_container[m_hashFunction(key)].Search([&](const PairType& nodePair) { return nodePair.first == key; });

        }

        UInt32 Hash(const KeyType& key) const
        {
            return m_hashFunction(key);
        }

        const ListType& GetContainer(UInt32 hash) const
        {
            assert(hash < DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY);
            return m_container[hash];
        }


        UInt64 GetSize() const
        {
            return m_size;
        }


    private:

        HashFunctionType m_hashFunction;
        
        ListType  m_container[DATASTRUCT_HASHTABLE_CONTAINER_CAPACITY];

        UInt64          m_size;

    };


    FRAMEWORK_CORE_DLL_FUNCTION UInt32 HashFunction(const UInt32& key);

}

#endif