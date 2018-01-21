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

	FMOD::Sound *pSound;
};

