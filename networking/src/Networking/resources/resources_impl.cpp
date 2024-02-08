#include "resources_impl.h"

namespace EM {
	std::vector<Resources::ResourceData*> Resources::mResources[RT_LAST];

	u32 Resources::getResourcePosition(ResourceType rt, const char * file)
	{
		size_t size = mResources[rt].size();

		u32 resourceId = static_cast<u32>(size);

		for (size_t i = 0; i < size; i++) {
			if (mResources[rt][i]->filePath == file) {
				resourceId = static_cast<u32>(i);
				break;
			}
		}

		return resourceId;
	}
}