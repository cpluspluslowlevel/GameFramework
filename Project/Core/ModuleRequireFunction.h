//////////////////////////////////////////////////////////////////////////////
// 모듈이 지원해야 하는 함수들의 목록입니다.
//////////////////////////////////////////////////////////////////////////////


#ifndef _FRAMEWORK_CORE_MODULEREQUIREFUNCTION_H_
#define _FRAMEWORK_CORE_MODULEREQUIREFUNCTION_H_

namespace Framework::Core
{



}

//직접 DLL에서 함수를 가져오는 구조이므로 C++형식의 이름으로 저장되지 않아야 하기에 이름 공간을 사용하지 않습니다.
#define FRAMEWORK_MODULE_INITIALIZE_FUNCTION_NAME       Framework_Module_Initialize
#define FRAMEWORK_MODULE_INITIALIZE_FUNCTION_DECLARE    Module* FRAMEWORK_MODULE_INITIALIZE_FUNCTION_NAME();



#endif