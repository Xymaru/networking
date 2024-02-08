#pragma once

#include "resources_impl.h"

#include <Networking/utilities/Image.h>

namespace EM {
	//--SPECIALIZATION FOR SPRITE
	template<>
	inline u32 Resources::Load<Image>(const char* file)
	{
		size_t size = mResources[ResourceType::RT_SPRITE].size();
		size_t i;

		Uint32 resourceId = -1;

		for (i = 0; i < size; i++) {
			if (mResources[RT_SPRITE][i]->filePath == file) {
				resourceId = static_cast<Uint32>(i);
				break;
			}
		}

		if (i == size) {
			Image* sprite = new Image();
			if (sprite->Init(file)) {
				ResourceData* resource = new ResourceData();

				resource->filePath = file;

				resource->resource = sprite;

				resourceId = static_cast<u32>(size);

				mResources[RT_SPRITE].push_back(resource);

				std::string message = "Loaded resource " + resource->filePath + " successfully.";
				Debug::Log("Resources", message.c_str());
			}
			else {
				Debug::LogError("Resources", SDL_GetError());

				delete sprite;
			}
		}

		return resourceId;
	}

	template<>
	inline Image* Resources::GetResourceById<Image>(ResourceId id)
	{
		Image* surface = NULL;

		if (id >= 0 && id < mResources[RT_SPRITE].size()) {
			surface = static_cast<Image*>(mResources[RT_SPRITE][id]->resource);
		}

		return surface;
	}

	template<>
	inline const char* Resources::GetResourcePath<Image>(ResourceId id)
	{
		return mResources[RT_SPRITE][id]->filePath.c_str();
	}
}