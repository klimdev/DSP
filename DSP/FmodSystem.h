#pragma once

#include <fmod.hpp>

class FmodSystemClass
{
public:
	FMOD::System* operator()() const;


	static const FmodSystemClass& singleton();
private:
	FmodSystemClass();
	~FmodSystemClass();

	FMOD::System           *pSystem;

	static FmodSystemClass singletonInstance;
};

extern const FmodSystemClass& FmodSystem;
