#pragma once
#include <fmod.hpp>
#include "ImGuiBase.h"

class SoundStream :
	public ImGuiBase
{
public:
	SoundStream();
	virtual ~SoundStream();

	// Inherited via ImGuiBase
	virtual void BeginDraw() override;
	virtual void InnerDraw() override;
	virtual void EndDraw() override;

	virtual FMOD_RESULT StreamReadCallback(FMOD_SOUND *sound, void *data, unsigned int datalen) = 0;
	virtual FMOD_RESULT StreamSetPosCallback (FMOD_SOUND *sound, int subsound, unsigned int position, FMOD_TIMEUNIT postype) = 0;

	FMOD::Sound *pSound;
};

