/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <cstdint>

namespace OvRendering::Settings
{
	/**
	* Enumeration of internal formats
	*/
	enum class EInternalFormat : uint8_t
	{
		// Base Internal Formats
		DEPTH_COMPONENT,
		DEPTH_STENCIL,
		RED,
		RG,
		RGB,
		RGBA,

		// Sized Internal Formats
		R8,
		R8_SNORM,
		R16,
		R16_SNORM,
		RG8,
		RG8_SNORM,
		RG16,
		RG16_SNORM,
		R3_G3_B2,
		RGB4,
		RGB5,
		RGB8,
		RGB8_SNORM,
		RGB10,
		RGB12,
		RGB16_SNORM,
		RGBA2,
		RGBA4,
		RGB5_A1,
		RGBA8,
		RGBA8_SNORM,
		RGB10_A2,
		RGB10_A2UI,
		RGBA12,
		RGBA16,
		SRGB8,
		SRGB8_ALPHA8,
		R16F,
		RG16F,
		RGB16F,
		RGBA16F,
		R32F,
		RG32F,
		RGB32F,
		RGBA32F,
		R11F_G11F_B10F,
		RGB9_E5,
		R8I,
		R8UI,
		R16I,
		R16UI,
		R32I,
		R32UI,
		RG8I,
		RG8UI,
		RG16I,
		RG16UI,
		RG32I,
		RG32UI,
		RGB8I,
		RGB8UI,
		RGB16I,
		RGB16UI,
		RGB32I,
		RGB32UI,
		RGBA8I,
		RGBA8UI,
		RGBA16I,
		RGBA16UI,
		RGBA32I,
		RGBA32UI,

		// Compressed Internal Formats
		COMPRESSED_RED,
		COMPRESSED_RG,
		COMPRESSED_RGB,
		COMPRESSED_RGBA,
		COMPRESSED_SRGB,
		COMPRESSED_SRGB_ALPHA,
		COMPRESSED_RED_RGTC1,
		COMPRESSED_SIGNED_RED_RGTC1,
		COMPRESSED_RG_RGTC2,
		COMPRESSED_SIGNED_RG_RGTC2,
		COMPRESSED_RGBA_BPTC_UNORM,
		COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
		COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
		COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	};
}