#ifndef _FRAMEWORK_CORE_MODULE_H_
#define _FRAMEWORK_CORE_MODULE_H_


namespace Framework::Core::Module
{


    class Module;

    

    class FRAMEWORK_CORE_DLL_CLASS ModuleContainer
    {
    public:
        ModuleContainer();
        ModuleContainer(const ModuleContainer&) = delete;                       //�Ŵ��������� �����ϰ� �ܺο��� ���� �������� �ʱ� ������ ���� �̵��� �������� �ʽ��ϴ�.
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