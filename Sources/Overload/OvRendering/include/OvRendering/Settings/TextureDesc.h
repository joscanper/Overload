/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <cstdint>

#include <OvRendering/Settings/ETextureFilteringMode.h>

namespace OvRendering::Settings
{
	/**
	* TODO
	*/
	struct TextureDesc
	{
		uint32_t width;
		uint32_t height;
		uint32_t bpp;
		Settings::ETextureFilteringMode firstFilter;
		Settings::ETextureFilteringMode secondFilter;
		bool generateMipmap;
	};
}