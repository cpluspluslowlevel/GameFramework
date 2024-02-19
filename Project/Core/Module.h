#ifndef _FRAMEWORK_CORE_MODULE_H_
#define _FRAMEWORK_CORE_MODULE_H_


namespace Framework::Core::Module
{


    class Module;

    

    class FRAMEWORK_CORE_DLL_CLASS ModuleContainer
    {
    public:
        ModuleContainer();
        ModuleContainer(const ModuleContainer&) = delete;                       //매니저에서만 생성하고 외부에선 새로 생성하지 않기 때문에 복사 이동은 지원하지 않습니다.
        ModuleContainer(ModuleContainer&&) noexcept = delete;
        ModuleContainer& operator=(const ModuleContainer&) noexcept = delete;
        ModuleContainer& operator=(ModuleContainer&&) = delete;
        ~ModuleContainer() noexcept = default;

        void Insert(std::string_view name, Module* module);

    private:

        DataStruct::Container::HashTable<std::string, Module*> m_moduleHashTable;

    };

    class FRAMEWORK_CORE_DLL_CLASS ModuleManager
    {
    public:

        ModuleContainer Container;

    private:



    };

}

#endif