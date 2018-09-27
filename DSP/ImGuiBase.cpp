#include "ImGuiBase.h"

#include <typeinfo>

char* ImGuiBase::GetNameWithId(std::string name, int64_t id)
{
	sprintf_s(m_windowName, "%s##%dll", name.c_str(), id);
	return m_windowName;
}

char* ImGuiBase::GetNameWithAlias(std::string name, std::string alias)
{
	sprintf_s(m_windowName, "%s##%s", name.c_str(), alias.c_str());
	return m_windowName;
}

char* ImGuiBase::GetNamePerInstance(std::string name)
{
	sprintf_s(m_windowName, "%s##%p", name.c_str(), this);
	return m_windowName;
}

char* ImGuiBase::GetNamePerClass(std::string name)
{
	sprintf_s(m_windowName, "%s##%s", name.c_str(), typeid(this).name());
	return m_windowName;
}
