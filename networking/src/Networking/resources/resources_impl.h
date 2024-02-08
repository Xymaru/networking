#pragma once
#pragma warning(disable : 4251)

#include <Networking/Core.h>

#include <Networking/SimpleTypes.h>

#include <sdl2/SDL.h>

#include <string>
#include <vector>

#include <Networking/Debug.h>

typedef u32 ResourceId;
typedef SDL_Surface Surface;

constexpr ResourceId EM_INVALID_RESOURCE = U32_MAX;

namespace EM {
	class EM_API Resources
	{
	private:
		Resources() = default;
		~Resources() = default;

		// Enum that indicates all the resources that can be loaded by the engine
		enum ResourceType {
			RT_SPRITE,
			RT_AUDIOCLIP,
			RT_SHADER,
			RT_FONT,
			RT_LAST
		};

		struct ResourceData {
			// Path to resource
			std::string filePath;

			// Any type
			void* resource;
		};

		static std::vector<ResourceData*> mResources[RT_LAST];

		static u32 getResourcePosition(ResourceType rt, const char* file);
	public:
		template<class T> static ResourceId Load(const char* file);
		template<class T> static T* GetResourceById(ResourceId id);
		
		template<class T> static const char* GetResourcePath(ResourceId id);
	};
}

// SPECIALIZATION FOR MIX_CHUNK
//template<>
//inline ResourceId Resources::Load<AudioClip>(const char * file)
//{
//	Uint32 size = static_cast<Uint32>(mResources[ResourceType::RT_AUDIOCLIP].size());
//	Uint32 i;
//
//	Uint32 resourceId = -1;
//
//	for (i = 0; i < size; i++) {
//		if (mResources[RT_AUDIOCLIP][i]->filePath == file) {
//			resourceId = static_cast<Uint32>(i);
//			break;
//		}
//	}
//
//	if (i == size) {
//		Mix_Chunk* audioclip = Mix_LoadWAV(file);
//
//		if (!audioclip) {
//			std::cout << Mix_GetError() << std::endl;
//		}
//		else {
//			Resource* resource = new Resource();
//
//			resource->resource = audioclip;
//
//			resource->filePath = file;
//
//			resourceId = static_cast<Uint32>(size);
//
//			mResources[RT_AUDIOCLIP].push_back(resource);
//
//			std::cout << "RESOURCES: Loaded " << file << std::endl;
//		}
//	}
//
//	return resourceId;
//}

//template<>
//inline AudioClip* Resources::GetResourceById<AudioClip>(ResourceId id)
//{
//	AudioClip* audioclip = NULL;
//
//	if (id >= 0 && id < mResources[RT_AUDIOCLIP].size()) {
//		audioclip = static_cast<AudioClip*>(mResources[RT_AUDIOCLIP][id]->resource);
//	}
//
//	return audioclip;
//}

// BOMBERMAN

// SPECIALIZATION FOR MAP

//template<>
//inline ResourceId Resources::Load<Map>(const char* file) {
//	Uint32 size = static_cast<Uint32>(mResources[ResourceType::RT_MAP].size());
//	Uint32 i;
//
//	Uint32 resourceId = -1;
//
//	for (i = 0; i < size; i++) {
//		if (mResources[RT_MAP][i]->filePath == file) {
//			resourceId = static_cast<Uint32>(i);
//			break;
//		}
//	}
//
//	if (i == size) {
//		Map* map = new Map();
//		map->LoadMap(file);
//
//		Resource* resource = new Resource();
//
//		resource->resource = map;
//
//		resource->filePath = file;
//
//		resourceId = static_cast<Uint32>(size);
//
//		mResources[RT_MAP].push_back(resource);
//
//		std::cout << "RESOURCES: Loaded " << file << std::endl;
//	}
//
//	return resourceId;
//}
//
//template<>
//inline Map* Resources::GetResourceById<Map>(ResourceId resource) {
//	Map* map = NULL;
//
//	if (resource >= 0 && resource < mResources[RT_MAP].size()) {
//		map = static_cast<Map*>(mResources[RT_MAP][resource]->resource);
//	}
//
//	return map;
//}
