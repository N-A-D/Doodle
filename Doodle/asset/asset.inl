namespace doodle {

	template<class Asset, class ...Args>
	inline void AssetManager::add(std::string name, Args && ...args) noexcept
	{
		if (!contains_table_for<Asset>())
			create_table_for<Asset>;
		name = normalize(name);
		assert(!has_aux<Asset>(name));
		db.at(Asset::family()).emplace(name, std::make_shared<Asset>(std::forward<Args>(args)...));
	}

	template<class Asset>
	inline void AssetManager::remove(std::string name) noexcept
	{
		assert(contains_table_for<Asset>());
		name = normalize(name);
		assert(has_aux<Asset>(name));
		db.at(Asset::family()).erase(name);
	}

	template<class Asset>
	inline Asset & AssetManager::get(std::string name) noexcept
	{
		assert(contains_table_for<Asset>());
		name = normalize(name);
		assert(has_aux<Asset>(name));
		return *(std::static_pointer_cast<Asset>(db.at(Asset::family()).at(name)));
	}

	template<class Asset>
	inline bool AssetManager::has(std::string name) const noexcept
	{
		assert(contains_table_for<Asset>());
		return has_aux<Asset>(normalize(name));
	}

	template<class Asset>
	inline void AssetManager::clear() noexcept
	{
		assert(contains_table_for<Asset>());
		db.at(Asset::family()).clear();
	}

	template<class Asset>
	inline bool AssetManager::contains_table_for() const noexcept
	{
		static_assert(std::is_base_of_v<BaseAsset, Asset>, "The asset type does not inherit from doodle::Asset!");
		return db.find(Asset::family()) != db.end();
	}

	template<class Asset>
	inline void AssetManager::create_table_for() noexcept
	{
		db.emplace(Asset::family(), AssetTable());
	}

	template<class Resource>
	inline bool AssetManager::has_aux(const std::string & name) const noexcept
	{
		auto& asset_table = db.at(Asset::family());
		return asset_table.find(name) != asset_table.end();
	}

}
