#ifndef _FRAMEWORK_CORE_MODULE_H_
#define _FRAMEWORK_CORE_MODULE_H_


namespace Framework::Core::Module
{

    class Module;

    class FRAMEWORK_CORE_DLL_CLASS ModuleContainer
    {
    public:
        ModuleContainer() = default;
        ModuleContainer(const ModuleContainer&) = delete;                       //�Ŵ��������� �����ϰ� �ܺο��� ���� �������� �ʱ� ������ ���� �̵��� �������� �ʽ��ϴ�.
        ModuleContainer(ModuleContainer&&) noexcept = delete;
        ~ModuleContainer() noexcept = default;
        ModuleContainer& operator=(const ModuleContainer&) noexcept = delete;
        ModuleContainer& operator=(ModuleContainer&&) = delete;


        bool Insert(const std::string& key, Module* module);

        Module* Search(const std::string& key);

    private:

        DataStruct::Container::HashTable<std::string, Module*> m_moduleHashTable;

    };

    class FRAMEWORK_CORE_DLL_CLASS ModuleManager
    {
    public:
        ModuleManager() = default;                            //����, �̵��� ���� �ʽ��ϴ�.
        ModuleManager(const ModuleManager&) = delete;
        ModuleManager(ModuleManager&&) noexcept = delete;
        ~ModuleManager() noexcept = default;
        ModuleManager& operator=(const ModuleManager&) = delete;
        ModuleManager& operator=(ModuleManager&&) noexcept = delete;


        ModuleContainer Container;



    private:



    };


    class FRAMEWORK_CORE_DLL_CLASS Module
    {
    public:
        Module() = default;
        Module(const Module& lvalue) = delete;
        Module(Module&& rvalue) noexcept = delete;
        ~Module() noexcept = default;
        Module& operator=(const Module& lvalue) = delete;
        Module& operator=(Module&& rvalue) noexcept = delete;

    private:

    };

}

#endif