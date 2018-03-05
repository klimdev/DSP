#include "SoundStream.h"

#include <cstring> // memset
#include "Common.h"
#include "FmodSystem.h"

FMOD_RESULT F_CALLBACK FMOD_SoundStreamReadCallBack(FMOD_SOUND *sound, void *data, unsigned int datalen)
{
	FMOD::Sound* pSound = reinterpret_cast<FMOD::Sound*>(sound);
	void* pUserData = nullptr;
	FMOD_CHECK(pSound->getUserData(&pUserData));
	SoundStream* pSoundStream = reinterpret_cast<SoundStream*>(pUserData);
	return pSoundStream->IsPlaying() ? pSoundStream->StreamReadCallback(data, datalen) : FMOD_OK;
}

FMOD_RESULT F_CALLBACK FMOD_SoundStreamSetPosCallBack(FMOD_SOUND *sound, int subsound, unsigned int position, FMOD_TIMEUNIT postype)
{
	FMOD::Sound* pSound = reinterpret_cast<FMOD::Sound*>(sound);
	void* pUserData = nullptr;
	FMOD_CHECK(pSound->getUserData(&pUserData));
	SoundStream* pSoundStream = reinterpret_cast<SoundStream*>(pUserData);
	return pSoundStream->IsPlaying() ? pSoundStream->StreamSetPosCallback(subsound, position, postype) : FMOD_OK;
}

SoundStream::SoundStream()
{
	// setting for steaming sound for my data
	FMOD_MODE               mode = FMOD_LOOP_NORMAL | FMOD_2D | FMOD_CREATESTREAM | FMOD_OPENUSER;
	
	//Create the sound.
	std::memset(&m_soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	m_soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);  // Required.
	m_soundInfo.numchannels = 2;                               // Number of channels in the sound. 
	m_soundInfo.defaultfrequency = 44100;                           // Default playback rate of sound. 
	m_soundInfo.decodebuffersize = 44100;                           // Chunk size of stream update in samples. This will be the amount of data passed to the user callback. 
	m_soundInfo.length = m_soundInfo.defaultfrequency * m_soundInfo.numchannels * sizeof(signed short) * 5; // Length of PCM data in bytes of whole song (for Sound::getLength) 
	m_soundInfo.format = FMOD_SOUND_FORMAT_PCM16;         // Data format of sound. 

	m_soundInfo.userdata = this;
	m_soundInfo.pcmreadcallback = FMOD_SoundStreamReadCallBack;                 // User callback for reading. 
	m_soundInfo.pcmsetposcallback = FMOD_SoundStreamSetPosCallBack;               // User callback for seeking. 
	FMOD_CHECK(FmodSystem()->createSound(0, mode, &m_soundInfo, &m_pSound));
}


SoundStream::~SoundStream()
{
	//stop sound
	StopStream();
	FMOD_CHECK(m_pSound->release());
}

FMOD_RESULT SoundStream::StreamSetPosCallback(int subsound, unsigned int position, FMOD_TIMEUNIT postype)
{
	return FMOD_OK;
}

void SoundStream::PlayStream()
{
	FMOD_CHECK(FmodSystem()->playSound(m_pSound, 0, m_pause, &m_pChannel));
}

void SoundStream::PauseStream()
{
	if (m_pChannel != nullptr)
	{
		bool playing = false;
		FMOD_CHECK(m_pChannel->isPlaying(&playing));
		if (playing)
		{
			m_pause = true;
			FMOD_CHECK(m_pChannel->setPaused(m_pause));
		}
		else
			m_pChannel = nullptr;
	}
}

void SoundStream::ResumeStream()
{
	if (m_pChannel != nullptr)
	{
		bool playing = false;
		FMOD_CHECK(m_pChannel->isPlaying(&playing));
		if (playing)
		{
			m_pause = false;
			FMOD_CHECK(m_pChannel->setPaused(m_pause));
		}
		else
			m_pChannel = nullptr;
	}
}

void SoundStream::ToggleStream()
{
	if (m_pChannel != nullptr)
	{
		bool playing = false;
		FMOD_CHECK(m_pChannel->isPlaying(&playing));
		if (playing)
		{
			FMOD_CHECK(m_pChannel->getPaused(&m_pause));
			m_pause = !m_pause;
			FMOD_CHECK(m_pChannel->setPaused(m_pause));
		}
		else
			m_pChannel = nullptr;
	}
}

void SoundStream::StopStream()
{
	if (m_pChannel != nullptr)
	{
		FMOD_CHECK(m_pChannel->stop());
		m_pChannel = nullptr;
	}
}

bool SoundStream::IsPlaying()
{
	bool playing = false;
	if (m_pChannel != nullptr)
		FMOD_CHECK(m_pChannel->isPlaying(&playing));
	return playing;
}


//demo
///*==============================================================================
//User Created Sound Example
//Copyright (c), Firelight Technologies Pty, Ltd 2004-2016.
//
//This example shows how create a sound with data filled by the user. It shows a
//user created static sample, followed by a user created stream. The former
//allocates all memory needed for the sound and is played back as a static sample,
//while the latter streams the data in chunks as it plays, using far less memory.
//==============================================================================*/
//#include "fmod.hpp"
//#include "common.h"
//#include <math.h>
//
//FMOD_RESULT F_CALLBACK pcmreadcallback(FMOD_SOUND* /*sound*/, void *data, unsigned int datalen)
//{
//	static float  t1 = 0, t2 = 0;        // time
//	static float  v1 = 0, v2 = 0;        // velocity
//	signed short *stereo16bitbuffer = (signed short *)data;
//
//	for (unsigned int count = 0; count < (datalen >> 2); count++)     // >>2 = 16bit stereo (4 bytes per sample)
//	{
//		*stereo16bitbuffer++ = (signed short)(Common_Sin(t1) * 32767.0f);    // left channel
//		*stereo16bitbuffer++ = (signed short)(Common_Sin(t2) * 32767.0f);    // right channel
//
//		t1 += 0.01f + v1;
//		t2 += 0.0142f + v2;
//		v1 += (float)(Common_Sin(t1) * 0.002f);
//		v2 += (float)(Common_Sin(t2) * 0.002f);
//	}
//
//	return FMOD_OK;
//}
//
//FMOD_RESULT F_CALLBACK pcmsetposcallback(FMOD_SOUND* /*sound*/, int /*subsound*/, unsigned int /*position*/, FMOD_TIMEUNIT /*postype*/)
//{
//	/*
//	This is useful if the user calls Channel::setPosition and you want to seek your data accordingly.
//	*/
//	return FMOD_OK;
//}
//
//int FMOD_Main()
//{
//	FMOD::System           *system;
//	FMOD::Sound            *sound;
//	FMOD::Channel          *channel = 0;
//	FMOD_RESULT             result;
//	FMOD_MODE               mode = FMOD_OPENUSER | FMOD_LOOP_NORMAL;
//	FMOD_CREATESOUNDEXINFO  exinfo;
//	unsigned int            version;
//	void                   *extradriverdata = 0;
//
//	Common_Init(&extradriverdata);
//
//	/*
//	Create a System object and initialize.
//	*/
//	result = FMOD::System_Create(&system);
//	ERRCHECK(result);
//
//	result = system->getVersion(&version);
//	ERRCHECK(result);
//
//	if (version < FMOD_VERSION)
//	{
//		Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
//	}
//
//	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
//	ERRCHECK(result);
//
//	do
//	{
//		Common_Update();
//
//		if (Common_BtnPress(BTN_ACTION1))
//		{
//			mode |= FMOD_CREATESTREAM;
//		}
//
//		result = system->update();
//		ERRCHECK(result);
//
//		Common_Draw("==================================================");
//		Common_Draw("User Created Sound Example.");
//		Common_Draw("Copyright (c) Firelight Technologies 2004-2016.");
//		Common_Draw("==================================================");
//		Common_Draw("");
//		Common_Draw("Sound played here is generated in realtime. It will either play as a stream which means it is continually filled as it is playing, or it will play as a static sample, which means it is filled once as the sound is created, then when played it will just play that short loop of data.");
//		Common_Draw("");
//		Common_Draw("Press %s to play an infinite generated stream", Common_BtnStr(BTN_ACTION1));
//		Common_Draw("Press %s to play a static looping sample", Common_BtnStr(BTN_ACTION2));
//		Common_Draw("");
//
//		Common_Sleep(50);
//	} while (!Common_BtnPress(BTN_ACTION1) && !Common_BtnPress(BTN_ACTION2) && !Common_BtnPress(BTN_QUIT));
//
//	/*
//	Create and play the sound.
//	*/
//	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
//	exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);  /* Required. */
//	exinfo.numchannels = 2;                               /* Number of channels in the sound. */
//	exinfo.defaultfrequency = 44100;                           /* Default playback rate of sound. */
//	exinfo.decodebuffersize = 44100;                           /* Chunk size of stream update in samples. This will be the amount of data passed to the user callback. */
//	exinfo.length = exinfo.defaultfrequency * exinfo.numchannels * sizeof(signed short) * 5; /* Length of PCM data in bytes of whole song (for Sound::getLength) */
//	exinfo.format = FMOD_SOUND_FORMAT_PCM16;         /* Data format of sound. */
//	exinfo.pcmreadcallback = pcmreadcallback;                 /* User callback for reading. */
//	exinfo.pcmsetposcallback = pcmsetposcallback;               /* User callback for seeking. */
//
//	result = system->createSound(0, mode, &exinfo, &sound);
//	ERRCHECK(result);
//
//	result = system->playSound(sound, 0, 0, &channel);
//	ERRCHECK(result);
//
//	/*
//	Main loop.
//	*/
//	do
//	{
//		Common_Update();
//
//		if (Common_BtnPress(BTN_ACTION1))
//		{
//			bool paused;
//			result = channel->getPaused(&paused);
//			ERRCHECK(result);
//			result = channel->setPaused(!paused);
//			ERRCHECK(result);
//		}
//
//		result = system->update();
//		ERRCHECK(result);
//
//		{
//			unsigned int ms = 0;
//			unsigned int lenms = 0;
//			bool         playing = false;
//			bool         paused = false;
//
//			if (channel)
//			{
//				result = channel->isPlaying(&playing);
//				if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE))
//				{
//					ERRCHECK(result);
//				}
//
//				result = channel->getPaused(&paused);
//				if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE))
//				{
//					ERRCHECK(result);
//				}
//
//				result = channel->getPosition(&ms, FMOD_TIMEUNIT_MS);
//				if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE))
//				{
//					ERRCHECK(result);
//				}
//
//				result = sound->getLength(&lenms, FMOD_TIMEUNIT_MS);
//				if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE))
//				{
//					ERRCHECK(result);
//				}
//			}
//
//			Common_Draw("==================================================");
//			Common_Draw("User Created Sound Example.");
//			Common_Draw("Copyright (c) Firelight Technologies 2004-2016.");
//			Common_Draw("==================================================");
//			Common_Draw("");
//			Common_Draw("Press %s to toggle pause", Common_BtnStr(BTN_ACTION1));
//			Common_Draw("Press %s to quit", Common_BtnStr(BTN_QUIT));
//			Common_Draw("");
//			Common_Draw("Time %02d:%02d:%02d/%02d:%02d:%02d : %s", ms / 1000 / 60, ms / 1000 % 60, ms / 10 % 100, lenms / 1000 / 60, lenms / 1000 % 60, lenms / 10 % 100, paused ? "Paused " : playing ? "Playing" : "Stopped");
//		}
//
//		Common_Sleep(50);
//	} while (!Common_BtnPress(BTN_QUIT));
//
//	/*
//	Shut down
//	*/
//	result = sound->release();
//	ERRCHECK(result);
//	result = system->close();
//	ERRCHECK(result);
//	result = system->release();
//	ERRCHECK(result);
//
//	Common_Close();
//
//	return 0;
//}
//