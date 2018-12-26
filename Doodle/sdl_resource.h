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
				, std::function<void(SDL_ResourceType* resource)> destructor)
				: resource(resource_ptr, destructor) {}
			virtual operator bool() const noexcept { return resource != nullptr; }
			virtual operator SDL_ResourceType*() const noexcept { return resource.get(); }
		protected:
			std::shared_ptr<SDL_ResourceType> resource;
		};

	}
}