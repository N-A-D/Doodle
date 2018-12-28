#pragma once

#include <string>
#include <SDL2/SDL_mixer.h>
#include "sdl_resource.h"
#include "asset.h"

namespace doodle {

	class Sound final 
		: public Asset<Sound>
		, public internal::SDLResource<Mix_Chunk> 
	{
	public:

		Sound(Mix_Chunk* chunk) noexcept;

		// Sets the volume for the sound sample
		void set_volume(int volume) noexcept;

		// Plays this sample
		// channel: The channel to play on. -1 for the first unreserved channel
		// loops: The number of times to loop. -1 is infinite.
		void play(int channel, int loops) const noexcept;

		// Timed playback of this sample
		// channel: The channel to play on. -1 for the first unreserved channel
		// loops: The number of times to loop. -1 is infinite.
		// duration: How long (milliseconds) to play the sample
		void play_timed(int channel, int loops, int duration) const noexcept;

		// Fade-in this sample
		// channel: The channel to play on. -1 for the first unreserved channel
		// loops: The number of times to loop. -1 is infinite.
		// fade_in_time: Time that the fade-in effect should take from silence to full volume 
		void fade_in(int channel, int loops, int fade_in_time) const noexcept;

		// Timed Fade-in of this sample
		// channel: The channel to play on. -1 for the first unreserved channel
		// loops: The number of times to loop. -1 is infinite.
		// fade_in_time: Time that the fade-in effect should take from silence to full volume 
		// duration: The time to play the sample.
		void fade_in_timed(int channel, int loops, int fade_in_time, int duration) const noexcept;

	};

	// Creates a new doodle::Sound object.
	Mix_Chunk* load_sound(const std::string& filename);

	// // Creates a new doodle::Sound object with a starting volume.
	Mix_Chunk* load_sound(const std::string& filename, int volume);
}

namespace doodle {
	namespace mixer {

		// Allocates a given number of channels
			// n: The number of channels to allocate
		void allocate_channels(int n) noexcept;

		// Sets the volume for a given channel
		// channel: The channel to set the volume for. -1 will set the volume for all allocated channels.
		void set_channel_volume(int channel, int volume) noexcept;

		// Pauses sample playback for a given channel
		// channel: The channel to pause playback. -1 will pause playback on all allocated channels.
		void pause_channel_playback(int channel) noexcept;

		// Resumes sample playback for a given channel
		// channel: The channel to resume playback. -1 will resume playback for all allocated channels
		void resume_channel_playback(int channel) noexcept;

		// Halts sample playback for a given channel
		// channel: The channel to halt playback. -1 will halt playback for all allocated channels
		void halt_channel_playback(int channel) noexcept;

		// Halts sample playback after a given time in milliseconds
		// channel: The channel to expire. -1 will halt playback for all allocated channels after the given duration
		void exipre_channel_playback(int channel, int duration) noexcept;

		// Fades out playback for a given channel
		// channel: The channel to fade out. -1 will fade out playback for all allocated channels
		// duration: The fade out time.
		void fade_out_channel(int channel, int duration) noexcept;

		// Returns the number of channels playing
		// channel: The channel to check. -1 will check if any of the allocated channels are playing
		int is_channel_playing(int channel) noexcept;

		// Returns the number of channels paused
		// channel: The channel to check. -1 will check if any of the allocated channels are paused
		int is_channel_paused(int channel) noexcept;

		// Sets the music volume
		// value: The music volume
		void set_music_volume(int volume) noexcept;

		// Pauses music playback
		void pause_music_playback() noexcept;

		// Resumes music playback
		void resume_music_playback() noexcept;

		// Rewinds the music to the start
		void rewind_music() noexcept;

		// Stops music playback
		void halt_music_playback() noexcept;

		// Fades out music
		// duration: The fade out time.
		void fade_out_music(int duration) noexcept;

		// Checks if music is actively playing or not
		bool is_music_playing() noexcept;

		// Checks if music is paused or not
		bool is_music_paused() noexcept;

	}
}
