//////////////////////////////////////////////////////////////////////////////
// ����� �����ؾ� �ϴ� �Լ����� ����Դϴ�.
//////////////////////////////////////////////////////////////////////////////


#ifndef _FRAMEWORK_CORE_MODULEREQUIREFUNCTION_H_
#define _FRAMEWORK_CORE_MODULEREQUIREFUNCTION_H_

namespace Framework::Core
{

    class Framework;

}

//���� DLL���� �Լ��� �������� �����̹Ƿ� C++������ �̸����� ������� �ʾƾ� �ϱ⿡ �̸� ������ ������� �ʽ��ϴ�.
#define FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME               Framework_Core_Module_Setup
#define FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME_STRING        "Framework_Core_Module_Setup"

using ModuleSetupFunction = void(*)(Framework::Core::Framework* setup);



#endif