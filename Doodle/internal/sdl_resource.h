#pragma once

#include <memory>
#include <functional>

namespace doodle {
	namespace internal {

		// The SDLResource class
		// The interface a class must implement in 
		// order to store an internal SDL resource. 
		template <class SDL_ResourceType>
		class SDLResource {
		public:
			SDLResource(SDL_ResourceType* resource_ptr
				, std::function<void(SDL_ResourceType* resource)> destructor) noexcept
				: resource(resource_ptr, destructor) {}
			operator SDL_ResourceType*() const noexcept { return resource.get(); }
		private:
			std::shared_ptr<SDL_ResourceType> resource;
		};

	}
}