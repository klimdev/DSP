#pragma once

#include <fmod.hpp>

class FmodSystemClass
{
public:
	FMOD::System* operator()() const;

private:
	FmodSystemClass();
	~FmodSystemClass();

	FMOD::System           *pSystem;
};

extern FmodSystemClass FmodSystem;
