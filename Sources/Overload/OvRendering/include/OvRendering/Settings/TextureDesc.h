/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/Settings/ETextureFilteringMode.h>
#include <OvRendering/Settings/ETextureWrapMode.h>
#include <OvRendering/Settings/EInternalFormat.h>
#include <OvRendering/Settings/EFormat.h>
#include <OvRendering/Settings/EPixelDataType.h>

namespace OvRendering::Settings
{
	/**
	* Structure that holds the description of a texture
	*/
	struct TextureDesc
	{
		uint32_t width = 1;
		uint32_t height = 1;
		ETextureFilteringMode firstFilter = ETextureFilteringMode::LINEAR;
		ETextureFilteringMode secondFilter = ETextureFilteringMode::LINEAR;
		ETextureWrapMode horizontalWrapMode = ETextureWrapMode::REPEAT;
		ETextureWrapMode verticalWrapMode = ETextureWrapMode::REPEAT;
		EInternalFormat internalFormat = EInternalFormat::RGBA;
		EFormat format = EFormat::RGBA;
		EPixelDataType type = EPixelDataType::UNSIGNED_BYTE;
		bool generateMipmap = true;
	};
}
