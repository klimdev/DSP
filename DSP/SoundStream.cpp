#include "SoundStream.h"

#include "Common.h"
#include "FmodSystem.h"

SoundStream::SoundStream()
{

	// setting for steaming sound for my data
	FMOD_MODE               mode = FMOD_LOOP_NORMAL | FMOD_2D | FMOD_CREATESTREAM | FMOD_OPENUSER | FMOD_OPENMEMORY_POINT;

	FMOD_CREATESOUNDEXINFO  exinfo;
	
	//Create and play the sound.
	
	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);  // Required.
	exinfo.numchannels = 2;                               // Number of channels in the sound. 
	exinfo.defaultfrequency = 44100;                           // Default playback rate of sound. 
	exinfo.decodebuffersize = 44100;                           // Chunk size of stream update in samples. This will be the amount of data passed to the user callback. 
	exinfo.length = exinfo.defaultfrequency * exinfo.numchannels * sizeof(signed short) * 5; // Length of PCM data in bytes of whole song (for Sound::getLength) 
	exinfo.format = FMOD_SOUND_FORMAT_PCM16;         // Data format of sound. 
	//exinfo.pcmreadcallback = pcmreadcallback;                 // User callback for reading. 
	//exinfo.pcmsetposcallback = pcmsetposcallback;               // User callback for seeking. 

	FMOD_CHECK(FmodSystem()->createSound(0, mode, &exinfo, &pSound));
}


SoundStream::~SoundStream()
{
	//stop sound

	FMOD_CHECK(pSound->release());
}

void SoundStream::BeginDraw()
{
	// small section (line(?) on whatever window it's on)
}

void SoundStream::InnerDraw()
{
	//button
	//if play -> pause button
	//else play button

	//stop button

	//if play checked
		//result = system->playSound(sound, 0, 0, &channel);
	//if paused checked
		//pause sound
	//if stop checked
		//stop sound

}

void SoundStream::EndDraw()
{
	//done
}
