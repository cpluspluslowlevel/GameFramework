#include "pch.h"
#include "Module.h"

namespace Framework::Core::Module
{

    bool ModuleContainer::Insert(const std::string& key, Module* module)
    {

        if (m_moduleHashTable.Insert(key, module) != DataStruct::Container::EHashTableInsertResult::Success)
        {
            return false;
        }

        return true;

    }

    Module* ModuleContainer::Search(const std::string& key)
    {

        auto searchNode{ m_moduleHashTable.SearchNode(key) };
        if (searchNode != nullptr)
        {
            return searchNode->value.second;
        }

        return nullptr;
    }

    void LoadModule()
    {
    }

}