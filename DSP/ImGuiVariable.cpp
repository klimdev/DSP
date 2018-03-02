#include "ImGuiVariable.h"

std::unordered_map<void*, ImGuiVarialbeUser::ImGuiVariableNameMap> ImGuiVarialbeUser::m_instanceVariableContainer = std::unordered_map<void*, ImGuiVarialbeUser::ImGuiVariableNameMap>();
ImGuiVarialbeUser::ImGuiVariableNameMap ImGuiVarialbeUser::m_globalVariableContrainer = ImGuiVarialbeUser::ImGuiVariableNameMap();