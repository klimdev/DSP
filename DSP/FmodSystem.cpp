#include "FmodSystem.h"

#include "Common.h"

FmodSystemClass FmodSystem;

FmodSystemClass::FmodSystemClass()
{
	/*
	Create a System object and initialize.
	*/
	FMOD_RESULT             result;
	unsigned int            version;
	void                   *extradriverdata = 0;

	FMOD_CHECK(FMOD::System_Create(&pSystem));

	FMOD_CHECK(pSystem->getVersion(&version));

	if (version < FMOD_VERSION)
	{
		//Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	FMOD_CHECK(pSystem->init(32, FMOD_INIT_NORMAL, extradriverdata));
}


FmodSystemClass::~FmodSystemClass()
{
	FMOD_CHECK(pSystem->close());
	FMOD_CHECK(pSystem->release());
}

FMOD::System * FmodSystemClass::operator()() const
{
	return pSystem;
}
