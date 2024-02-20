#include "pch.h"
#include "Framework.h"

#include "Module.h"
#include "ModuleRequireFunction.h"

namespace Framework::Core
{

    bool Framework::LoadModule(std::wstring_view fileName)
    {

        HMODULE moduleHandle{ LoadLibrary(fileName.data()) };
        if (moduleHandle == NULL)
        {
            return false;
        }

        ModuleSetupFunction setupFunction{ (ModuleSetupFunction)GetProcAddress(moduleHandle, FRAMEWORK_CORE_MODULE_SETUP_FUNCTION_NAME_STRING) };
        if (setupFunction != nullptr)
        {

            setupFunction(this);

        }

        return true;

    }

    void Framework::Run()
    {
    }

}