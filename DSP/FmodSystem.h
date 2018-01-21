#pragma once

#include <fmod.hpp>

class FmodSystem
{
public:
	FmodSystem();
	~FmodSystem();

	FMOD::System           *pSystem;
};

