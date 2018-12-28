#include "asset.h"
#include <cctype>
#include <algorithm>

void doodle::AssetManager::clear_all() noexcept
{
	db.clear();
}

std::string doodle::AssetManager::normalize(std::string name) const noexcept
{
	name.erase(
		std::remove_if(name.begin(), name.end(), 
		[](unsigned char c) { 
			return std::isspace(c) || !std::isalnum(c); 
		}), 
		name.end()
	);
	std::transform(name.begin(), name.end(), name.begin(), 
		[](unsigned char c) {
			return std::tolower(c);
		}
	);
	return name;
}
