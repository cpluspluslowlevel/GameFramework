#ifndef _FRAMEWORK_GRAPHICSDX12_MODULE_H_
#define _FRAMEWORK_GRAPHICSDX12_MODULE_H_

#include "../Core/ModuleRequireFunction.h"

namespace Framework::GraphicsDX12
{

    namespace Module
    {
    }

}

//직접링크를 지원하기 때문에 C스타일 이름을 사용해야합니다. 따라서 네임스페이스를 사용하지 않습니다.
FRAMEWORK_GRAPHICSDX12_DLL_FUNCTION_C void FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME(class Framework::Core::Framework* framework);

#endif