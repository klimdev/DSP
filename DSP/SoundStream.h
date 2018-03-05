#pragma once
#include <fmod.hpp>

class SoundStream
{
public:
	SoundStream();
	virtual ~SoundStream();

	virtual FMOD_RESULT StreamReadCallback(void *pData, unsigned int datalen) = 0;
	virtual FMOD_RESULT StreamSetPosCallback (int subsound, unsigned int position, FMOD_TIMEUNIT postype);

	void PlayStream();
	void PauseStream();
	void ResumeStream();
	void ToggleStream();
	void StopStream();
	bool IsPlaying();


	bool m_pause = false;
	FMOD_CREATESOUNDEXINFO  m_soundInfo;
protected:
	FMOD::Channel *m_pChannel = nullptr;
	FMOD::Sound *m_pSound;
};

