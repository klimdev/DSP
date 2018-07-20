#pragma once
#include <unordered_map>
#include <memory>

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

	template<typename T>
	T& GlobalVariable(const char* name)
	{
		return GlobalVariable<T>(std::string(name));
	}
	template<typename T>
	T& GlobalVariable(const std::string& name)
	{
		if (m_globalVariableContrainer.find(name) == map.end())
			m_globalVariableContrainer[name] = new ImGuiVariable<T>();

		return *reinterpret_cast<T*>(m_globalVariableContrainer[name]->Get())
	}

	template<typename T>
	T& GlobalVariable(const char* name, T defaultValue)
	{
		return GlobalVariable<T>(std::string(name), defaultValue);
	}
	template<typename T>
	T& GlobalVariable(const std::string& name, T defaultValue)
	{
		if (m_globalVariableContrainer.find(name) == map.end())
			m_globalVariableContrainer[name] = new ImGuiVariable<T>(defaultValue);

		return *reinterpret_cast<T*>(m_globalVariableContrainer[name]->Get())
	}

private:
	typedef std::unordered_map< std::string, ImGuiVariableBase* > ImGuiVariableNameMap;
	ImGuiVariableNameMap m_instanceVariableContainer;
	static ImGuiVariableNameMap m_globalVariableContrainer;
};