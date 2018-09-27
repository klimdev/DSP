#pragma once
#include <unordered_map>
#include <memory>
#include <typeinfo>

class ImGuiVarialbeUser
{
private:
	class ImGuiVariableBase	
	{	
	public:
		virtual void* Get() { return nullptr; }
	};

	template<typename T>
	class ImGuiVariable : public ImGuiVariableBase 
	{
	public:
		ImGuiVariable() { }
		ImGuiVariable(const T& defaultValue) : m_variable(defaultValue) { }
		virtual void* Get() override { return &m_variable; }
	protected:
		T m_variable;
	};

public:
	virtual ~ImGuiVarialbeUser()
	{
		ImGuiVariableNameMap& map = m_instanceVariableContainer;
		ImGuiVariableNameMap::iterator iterator = map.begin();
		while (iterator != map.end())
		{
			delete iterator->second;
			++iterator;
		}
	}

#pragma region LocalVariable
	template<typename T>
	T& Variable(const char* name)
	{
		return Variable<T>(std::string(name));
	}
	template<typename T>
	T& Variable(const std::string& name)
	{
		ImGuiVariableNameMap& map = m_instanceVariableContainer;
		if (map.find(name) == map.end())
			map[name] = new ImGuiVariable<T>();

		return *reinterpret_cast<T*>(map[name]->Get());
	}

	template<typename T>
	T& Variable(const char* name, T defaultValue)
	{
		return Variable<T>(std::string(name), defaultValue);
	}
	template<typename T>
	T& Variable(const std::string& name, T defaultValue)
	{
		ImGuiVariableNameMap& map = m_instanceVariableContainer;
		if (map.find(name) == map.end())
			map[name] = new ImGuiVariable<T>(defaultValue);

		return *reinterpret_cast<T*>(map[name]->Get());
	}
#pragma endregion

#pragma region ClassVariable
	template<typename T>
	T& ClassVariable(const char* name)
	{
		return ClassVariable<T>(std::string(name));
	}
	template<typename T>
	T& ClassVariable(const std::string& name)
	{
		ImGuiVariableNameMap& map = m_classVariableContainer[typeid(this).hash_code()];
		if (map.find(name) == map.end())
			map[name] = new ImGuiVariable<T>();

		return *reinterpret_cast<T*>(map[name]->Get());
	}

	template<typename T>
	T& ClassVariable(const char* name, T defaultValue)
	{
		return ClassVariable<T>(std::string(name), defaultValue);
	}
	template<typename T>
	T& ClassVariable(const std::string& name, T defaultValue)
	{
		ImGuiVariableNameMap& map = m_classVariableContainer[typeid(this).hash_code()];
		if (map.find(name) == map.end())
			map[name] = new ImGuiVariable<T>(defaultValue);

		return *reinterpret_cast<T*>(map[name]->Get());
	}
#pragma endregion

#pragma region GlobalVariable
	template<typename T>
	T& GlobalVariable(const char* name)
	{
		return GlobalVariable<T>(std::string(name));
	}
	template<typename T>
	T& GlobalVariable(const std::string& name)
	{
		if (m_globalVariableContainer.find(name) == map.end())
			m_globalVariableContainer[name] = new ImGuiVariable<T>();

		return *reinterpret_cast<T*>(m_globalVariableContainer[name]->Get());
	}

	template<typename T>
	T& GlobalVariable(const char* name, T defaultValue)
	{
		return GlobalVariable<T>(std::string(name), defaultValue);
	}
	template<typename T>
	T& GlobalVariable(const std::string& name, T defaultValue)
	{
		if (m_globalVariableContainer.find(name) == map.end())
			m_globalVariableContainer[name] = new ImGuiVariable<T>(defaultValue);

		return *reinterpret_cast<T*>(m_globalVariableContainer[name]->Get());
	}
#pragma endregion

private:
	typedef std::unordered_map< std::string, ImGuiVariableBase* > ImGuiVariableNameMap;
	ImGuiVariableNameMap m_instanceVariableContainer;
	static std::unordered_map< size_t, ImGuiVariableNameMap > m_classVariableContainer;
	static ImGuiVariableNameMap m_globalVariableContainer;
};