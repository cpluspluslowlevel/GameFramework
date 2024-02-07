#ifndef _FRAMEWORK_CORE_HASHTABLE_H_
#define _FRAMEWORK_CORE_HASHTABLE_H_

namespace Framework::Core::DataStruct
{


    template<typename _KeyType, typename _ValueType>
    class HashTable
    {
    public:

        using KeyType   = _KeyType;
        using ValueType = _ValueType;

        struct ELEMENT
        {
            KeyType     key;
            ValueType   value;
        };

        using ElementType = ELEMENT;

    private:



    };

}

#endif