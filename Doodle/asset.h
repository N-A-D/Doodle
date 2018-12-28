#pragma once

#include <memory>
#include <string>
#include <cassert>
#include <cstddef>
#include <type_traits>
#include <unordered_map>
#include "noncopyable.h"

namespace doodle {

	using AssetFamily = std::size_t;

	// The BasicAsset class
	class BasicAsset {
	public:
		BasicAsset() = default;
		virtual ~BasicAsset() = default;
	protected:
		static AssetFamily family_id;
	};

	class AssetManager;

	// The Asset class
	// Classes that are meant to be 'assets' must inherit this class for use in a doodle::AssetManager.
	template <class T>
	class Asset : public BasicAsset {
	public:
		Asset() = default;
		virtual ~Asset() = default;
	private:
		friend class AssetManager;
		// Returns the type id of an Asset type.
		AssetFamily family() noexcept {
			static AssetFamily id = family_id++;
			return id;
		}
	};

	// The AssetManager class
	// Manages multiple named assets for any given Asset type.
	// Note:
	// - An 'Asset' must be a class that inherits from the class doodle::Asset above.
	class AssetManager final : internal::NonCopyable {
	public:
		AssetManager() = default;

		// Reduce typing
		using AssetTable = std::unordered_map<std::string, std::shared_ptr<BasicAsset>>;
		using AssetDatabase = std::unordered_map<AssetFamily, AssetTable>;

		// Manage a new named asset.
		// Note:
		// - Builds a new asset table for the asset type.
		// - Asserts there does not exist an asset with the given name.
		template <class Asset, class... Args>
		void add(std::string name, Args&&... args) noexcept;

		// Remove an existing named asset.
		// Note:
		// - Asserts there exists an asset with the given name.
		template <class Asset>
		void remove(std::string name) noexcept;

		// Returns the asset bound to the given name.
		// Note:
		// - Asserts there exists an asset with the given name.
		template <class Asset>
		Asset& get(std::string name) noexcept;

		// Checks if the exists an asset with the given name.
		template <class Asset>
		bool has(std::string name) const noexcept;

		// Removes all named assets belonging to a given Asset type.
		template <class Asset>
		void clear() noexcept; 

		// Remove all assets.
		void clear_all() noexcept;

	private:

		// Checks if there is an asset database for the asset type.
		template <class Asset>
		bool contains_table_for() const noexcept;

		// Creates an asset database for the asset type.
		template <class Asset>
		void create_table_for() noexcept;

		// Checks if there exists an Asset with the given name w/o normalization.
		template <class Resource>
		bool has_aux(const std::string& name) const noexcept;

		// Returns a lowercase version of the asset name (no spaces & non alphanueric characters)
		std::string normalize(std::string name) const noexcept;

		// Per Asset type named asset table.
		AssetDatabase db;
	};

}
#include "asset.inl"
