#include "ImGuiVariable.h"

std::unordered_map< size_t, ImGuiVarialbeUser::ImGuiVariableNameMap > ImGuiVarialbeUser::m_classVariableContainer = std::unordered_map< size_t, ImGuiVarialbeUser::ImGuiVariableNameMap >();
ImGuiVarialbeUser::ImGuiVariableNameMap ImGuiVarialbeUser::m_globalVariableContainer = ImGuiVarialbeUser::ImGuiVariableNameMap();