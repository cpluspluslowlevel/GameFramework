//////////////////////////////////////////////////////////////////////////////
// 모듈이 지원해야 하는 함수들의 목록입니다.
//////////////////////////////////////////////////////////////////////////////


#ifndef _FRAMEWORK_CORE_MODULEREQUIREFUNCTION_H_
#define _FRAMEWORK_CORE_MODULEREQUIREFUNCTION_H_

namespace Framework::Core
{

    class Framework;

}

//직접 DLL에서 함수를 가져오는 구조이므로 C++형식의 이름으로 저장되지 않아야 하기에 이름 공간을 사용하지 않습니다.
#define FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME               Framework_Core_Module_Setup
#define FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME_STRING        "Framework_Core_Module_Setup"

using ModuleSetupFunction = void(*)(Framework::Core::Framework* setup);



#endif