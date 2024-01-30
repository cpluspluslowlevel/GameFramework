#ifndef _FRAMEWORK_CORE_MODULE_H_
#define _FRAMEWORK_CORE_MODULE_H_

namespace Framework::Core::DataStruct
{


    template<typename _KeyType, typename _ValueType>
    class HashTable
    {
    public:

        using KeyType   = _KeyType;
        using ValueType = _ValueType;

        struct Element
        {
            KeyType     key;
            ValueType   value;
        };

    private:



    };

}

#endif