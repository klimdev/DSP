#pragma once
#include <fmod.hpp>

#define FMOD_CHECK(_result) { FMOD_RESULT CurrentFMODResultCode = _result; if (CurrentFMODResultCode != FMOD_OK) __debugbreak(); };