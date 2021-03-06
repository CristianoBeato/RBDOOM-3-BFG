/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.
Copyright (C) 2013 Robert Beckebans

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
#ifndef __SDL_SOUNDHARDWARE_H__
#define __SDL_SOUNDHARDWARE_H__

class idSoundSample_SDL;
class idSoundVoice_SDL;
class idSoundHardware_SDL;



/*
================================================
idSoundHardware_SDL
================================================
*/

class idSoundHardware_SDL
{
public:
	idSoundHardware_SDL();
	
	void			Init();
	void			Shutdown();
	
	void 			Update();
	
	idSoundVoice* 	AllocateVoice( const idSoundSample* leadinSample, const idSoundSample* loopingSample );
	void			FreeVoice( idSoundVoice* voice );
	
	// listDevices needs this
	ALCdevice* 		GetOpenALDevice() const
	{
		return openalDevice;
	};
	
	int				GetNumZombieVoices() const
	{
		return zombieVoices.Num();
	}

	int				GetNumFreeVoices() const
	{
		return freeVoices.Num();
	}
	
	// OpenAL info
	static void		PrintDeviceList( const char* list );
	static void		PrintSDLCInfo( ALCdevice* device );
	static void		PrintSDLnfo(void);
	
protected:
	friend class idSoundSample_OpenAL;
	friend class idSoundVoice_OpenAL;

	uint32	sdlNumAudioDrivers;
	
private:
};

/*
================================================
idSoundHardware
================================================
*/
class idSoundHardware : public idSoundHardware_SDL
{
};

#endif //!__SDL_SOUNDHARDWARE_H__
