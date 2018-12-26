#include "sound.h"
#include <stdexcept>
#include <string>

void doodle::Sound::set_volume(int volume) noexcept
{
	Mix_VolumeChunk(*this, volume);
}

void doodle::Sound::play(int channel, int loops) const noexcept
{
	Mix_PlayChannel(channel, *this, loops);
}

void doodle::Sound::play_timed(int channel, int loops, int duration) const noexcept
{
	Mix_PlayChannelTimed(channel, *this, loops, duration);
}

void doodle::Sound::fade_in(int channel, int loops, int fade_in_time) const noexcept
{
	Mix_FadeInChannel(channel, *this, loops, fade_in_time);
}

void doodle::Sound::fade_in_timed(int channel, int loops, int fade_in_time, int duration) const noexcept
{
	Mix_FadeInChannelTimed(channel, *this, loops, fade_in_time, duration);
}

doodle::Sound::Sound(Mix_Chunk * chunk)
	: SDLResource(chunk, [](Mix_Chunk* chunk) { Mix_FreeChunk(chunk); })
{
}

doodle::Sound doodle::load_sound(const std::string & filename)
{
	auto mix_chunk = Mix_LoadWAV(filename.c_str());
	if (!mix_chunk)
		throw std::runtime_error("Could not create doodle::Sound " + std::string(Mix_GetError()));
	return Sound(mix_chunk);
}

doodle::Sound doodle::load_sound(const std::string & filename, int volume)
{
	auto mix_chunk = Mix_LoadWAV(filename.c_str());
	if (!mix_chunk)
		throw std::runtime_error("Could not create doodle::Sound " + std::string(Mix_GetError()));
	Mix_VolumeChunk(mix_chunk, volume);
	return Sound(mix_chunk);
}

void doodle::mixer::allocate_channels(int n) noexcept
{
	Mix_AllocateChannels(n);
}

void doodle::mixer::set_channel_volume(int channel, int volume) noexcept
{
	Mix_Volume(channel, volume);
}

void doodle::mixer::pause_channel_playback(int channel) noexcept
{
	Mix_Pause(channel);
}

void doodle::mixer::resume_channel_playback(int channel) noexcept
{
	Mix_Resume(channel);
}

void doodle::mixer::halt_channel_playback(int channel) noexcept
{
	Mix_HaltChannel(channel);
}

void doodle::mixer::exipre_channel_playback(int channel, int duration) noexcept
{
	Mix_ExpireChannel(channel, duration);
}

void doodle::mixer::fade_out_channel(int channel, int duration) noexcept
{
	Mix_FadeOutChannel(channel, duration);
}

int doodle::mixer::is_channel_playing(int channel) noexcept
{
	return Mix_Playing(channel);
}

int doodle::mixer::is_channel_paused(int channel) noexcept
{
	return Mix_Paused(channel);
}

void doodle::mixer::set_music_volume(int volume) noexcept
{
	Mix_VolumeMusic(volume);
}

void doodle::mixer::pause_music_playback() noexcept
{
	Mix_PauseMusic();
}

void doodle::mixer::resume_music_playback() noexcept
{
	Mix_ResumeMusic();
}

void doodle::mixer::rewind_music() noexcept
{
	Mix_ResumeMusic();
}

void doodle::mixer::halt_music_playback() noexcept
{
	Mix_HaltMusic();
}

void doodle::mixer::fade_out_music(int duration) noexcept
{
	Mix_FadeOutMusic(duration);
}

bool doodle::mixer::is_music_playing() noexcept
{
	return  Mix_PlayingMusic() != 0 ? true : false;
}

bool doodle::mixer::is_music_paused() noexcept
{
	return  Mix_PausedMusic() != 0 ? true : false;
}
