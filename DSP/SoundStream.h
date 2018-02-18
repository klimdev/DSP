#pragma once
#include <fmod.hpp>

class SoundStream
{
public:
	SoundStream();
	virtual ~SoundStream();

	virtual FMOD_RESULT StreamReadCallback(void *data, unsigned int datalen) = 0;
	virtual FMOD_RESULT StreamSetPosCallback (int subsound, unsigned int position, FMOD_TIMEUNIT postype) = 0;

	FMOD::Sound *pSound;
};

