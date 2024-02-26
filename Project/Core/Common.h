#ifndef _FRAMEWORK_CORE_COMMON_H_
#define _FRAMEWORK_CORE_COMMON_H_

#include "CommonConstant.h"
#include "CommonStruct.h"

namespace Framework::Core
{

    template<typename Type> requires std::is_pointer_v<Type>
    void SafeDelete(Type& value)
    {
        delete value;
        value = nullptr;
    }

    template<typename Type> requires std::is_pointer_v<Type>
    void SafeRelease(Type& value)
    {
        if (value != nullptr)
        {
            value->Release();
            value = nullptr;
        }
    }

}

#endif