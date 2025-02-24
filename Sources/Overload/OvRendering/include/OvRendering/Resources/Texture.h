/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <cstdint>
#include <string>

#include <OvRendering/Settings/ETextureFilteringMode.h>
#include <OvRendering/HAL/Texture.h>

namespace OvRendering::Resources
{
	namespace Loaders { class TextureLoader; }

	/**
	* Texture saved on the disk
	*/
	class Texture : public HAL::Texture
	{
		friend class Loaders::TextureLoader;

	private:
		Texture(const std::string p_path);
		~Texture() = default;

	public:
		const std::string path;
	};
}