#pragma once

#include <sdl2/SDL_mixer.h>
#include <Networking/SimpleTypes.h>
#include <Networking/Core.h>

struct EM_API AudioClip
{
	// Mix Chunk
	Mix_Chunk* Chunk;

	// Duration in seconds
	u32 Duration;
};