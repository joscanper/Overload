/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <GL/glew.h>

#include <OvRendering/Settings/ECullFace.h>
#include <OvRendering/Settings/ETextureFilteringMode.h>
#include <OvRendering/Settings/ETextureWrapMode.h>
#include <OvRendering/Settings/ERasterizationMode.h>
#include <OvRendering/Settings/EPrimitiveMode.h>
#include <OvRendering/Settings/ERenderingCapability.h>
#include <OvRendering/Settings/EOperation.h>
#include <OvRendering/Settings/EComparaisonAlgorithm.h>
#include <OvRendering/Settings/EFormat.h>
#include <OvRendering/Settings/EInternalFormat.h>
#include <OvRendering/Settings/EPixelDataFormat.h>
#include <OvRendering/Settings/EPixelDataType.h>
#include <OvRendering/Settings/EDataType.h>
#include <OvRendering/Settings/EAccessSpecifier.h>
#include <OvRendering/Settings/UniformType.h>

constexpr GLenum ToGLEnum(OvRendering::Settings::ERasterizationMode value)
{
	return GL_POINT + static_cast<GLint>(value);
}

constexpr GLenum ToGLEnum(OvRendering::Settings::EComparaisonAlgorithm value)
{
	return GL_NEVER + static_cast<GLint>(value);
}

constexpr GLenum ToGLEnum(OvRendering::Settings::ECullFace value)
{
	switch (value)
	{
	case OvRendering::Settings::ECullFace::FRONT: return GL_FRONT;
	case OvRendering::Settings::ECullFace::BACK: return GL_BACK;
	case OvRendering::Settings::ECullFace::FRONT_AND_BACK: return GL_FRONT_AND_BACK;
	}
	return {};
}

constexpr GLenum ToGLEnum(OvRendering::Settings::EOperation value)
{
	switch (value)
	{
	case OvRendering::Settings::EOperation::KEEP: return GL_KEEP;
	case OvRendering::Settings::EOperation::ZERO: return GL_ZERO;
	case OvRendering::Settings::EOperation::REPLACE: return GL_REPLACE;
	case OvRendering::Settings::EOperation::INCREMENT: return GL_INCR;
	case OvRendering::Settings::EOperation::INCREMENT_WRAP: return GL_INCR_WRAP;
	case OvRendering::Settings::EOperation::DECREMENT: return GL_DECR;
	case OvRendering::Settings::EOperation::DECREMENT_WRAP: return GL_DECR_WRAP;
	case OvRendering::Settings::EOperation::INVERT: return GL_INVERT;
	}
	return {};
}

constexpr GLenum ToGLEnum(OvRendering::Settings::ERenderingCapability value)
{
	switch (value)
	{
	case OvRendering::Settings::ERenderingCapability::BLEND: return GL_BLEND;
	case OvRendering::Settings::ERenderingCapability::CULL_FACE: return GL_CULL_FACE;
	case OvRendering::Settings::ERenderingCapability::DEPTH_TEST: return GL_DEPTH_TEST;
	case OvRendering::Settings::ERenderingCapability::DITHER: return GL_DITHER;
	case OvRendering::Settings::ERenderingCapability::POLYGON_OFFSET_FILL: return GL_POLYGON_OFFSET_FILL;
	case OvRendering::Settings::ERenderingCapability::SAMPLE_ALPHA_TO_COVERAGE: return GL_SAMPLE_ALPHA_TO_COVERAGE;
	case OvRendering::Settings::ERenderingCapability::SAMPLE_COVERAGE: return GL_SAMPLE_COVERAGE;
	case OvRendering::Settings::ERenderingCapability::SCISSOR_TEST: return GL_SCISSOR_TEST;
	case OvRendering::Settings::ERenderingCapability::STENCIL_TEST: return GL_STENCIL_TEST;
	case OvRendering::Settings::ERenderingCapability::MULTISAMPLE: return GL_MULTISAMPLE;
	}
	return {};
}

constexpr GLenum ToGLEnum(OvRendering::Settings::EPrimitiveMode value)
{
	switch (value)
	{
	case OvRendering::Settings::EPrimitiveMode::POINTS: return GL_POINTS;
	case OvRendering::Settings::EPrimitiveMode::LINES: return GL_LINES;
	case OvRendering::Settings::EPrimitiveMode::LINE_LOOP: return GL_LINE_LOOP;
	case OvRendering::Settings::EPrimitiveMode::LINE_STRIP: return GL_LINE_STRIP;
	case OvRendering::Settings::EPrimitiveMode::TRIANGLES: return GL_TRIANGLES;
	case OvRendering::Settings::EPrimitiveMode::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
	case OvRendering::Settings::EPrimitiveMode::TRIANGLE_FAN: return GL_TRIANGLE_FAN;
	case OvRendering::Settings::EPrimitiveMode::LINES_ADJACENCY: return GL_LINES_ADJACENCY;
	case OvRendering::Settings::EPrimitiveMode::LINE_STRIP_ADJACENCY: return GL_LINE_STRIP_ADJACENCY;
	case OvRendering::Settings::EPrimitiveMode::PATCHES: return GL_PATCHES;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::EFormat value)
{
	switch (value)
	{
	case OvRendering::Settings::EFormat::RED: return GL_RED;
	case OvRendering::Settings::EFormat::RG: return GL_RG;
	case OvRendering::Settings::EFormat::RGB: return GL_RGB;
	case OvRendering::Settings::EFormat::BGR: return GL_BGR;
	case OvRendering::Settings::EFormat::RGBA: return GL_RGBA;
	case OvRendering::Settings::EFormat::BGRA: return GL_BGRA;
	case OvRendering::Settings::EFormat::RED_INTEGER: return GL_RED_INTEGER;
	case OvRendering::Settings::EFormat::RG_INTEGER: return GL_RG_INTEGER;
	case OvRendering::Settings::EFormat::RGB_INTEGER: return GL_RGB_INTEGER;
	case OvRendering::Settings::EFormat::BGR_INTEGER: return GL_BGR_INTEGER;
	case OvRendering::Settings::EFormat::RGBA_INTEGER: return GL_RGBA_INTEGER;
	case OvRendering::Settings::EFormat::BGRA_INTEGER: return GL_BGRA_INTEGER;
	case OvRendering::Settings::EFormat::STENCIL_INDEX: return GL_STENCIL_INDEX;
	case OvRendering::Settings::EFormat::DEPTH_COMPONENT: return GL_DEPTH_COMPONENT;
	case OvRendering::Settings::EFormat::DEPTH_STENCIL: return GL_DEPTH_STENCIL;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::EInternalFormat value)
{
	switch (value)
	{
	case OvRendering::Settings::EInternalFormat::DEPTH_COMPONENT: return GL_DEPTH_COMPONENT;
	case OvRendering::Settings::EInternalFormat::DEPTH_STENCIL: return GL_DEPTH_STENCIL;
	case OvRendering::Settings::EInternalFormat::RED: return GL_RED;
	case OvRendering::Settings::EInternalFormat::RG: return GL_RG;
	case OvRendering::Settings::EInternalFormat::RGB: return GL_RGB;
	case OvRendering::Settings::EInternalFormat::RGBA: return GL_RGBA;
	case OvRendering::Settings::EInternalFormat::R8: return GL_R8;
	case OvRendering::Settings::EInternalFormat::R8_SNORM: return GL_R8_SNORM;
	case OvRendering::Settings::EInternalFormat::R16: return GL_R16;
	case OvRendering::Settings::EInternalFormat::R16_SNORM: return GL_R16_SNORM;
	case OvRendering::Settings::EInternalFormat::RG8: return GL_RG8;
	case OvRendering::Settings::EInternalFormat::RG8_SNORM: return GL_RG8_SNORM;
	case OvRendering::Settings::EInternalFormat::RG16: return GL_RG16;
	case OvRendering::Settings::EInternalFormat::RG16_SNORM: return GL_RG16_SNORM;
	case OvRendering::Settings::EInternalFormat::R3_G3_B2: return GL_R3_G3_B2;
	case OvRendering::Settings::EInternalFormat::RGB4: return GL_RGB4;
	case OvRendering::Settings::EInternalFormat::RGB5: return GL_RGB5;
	case OvRendering::Settings::EInternalFormat::RGB8: return GL_RGB8;
	case OvRendering::Settings::EInternalFormat::RGB8_SNORM: return GL_RGB8_SNORM;
	case OvRendering::Settings::EInternalFormat::RGB10: return GL_RGB10;
	case OvRendering::Settings::EInternalFormat::RGB12: return GL_RGB12;
	case OvRendering::Settings::EInternalFormat::RGB16_SNORM: return GL_RGB16_SNORM;
	case OvRendering::Settings::EInternalFormat::RGBA2: return GL_RGBA2;
	case OvRendering::Settings::EInternalFormat::RGBA4: return GL_RGBA4;
	case OvRendering::Settings::EInternalFormat::RGB5_A1: return GL_RGB5_A1;
	case OvRendering::Settings::EInternalFormat::RGBA8: return GL_RGBA8;
	case OvRendering::Settings::EInternalFormat::RGBA8_SNORM: return GL_RGBA8_SNORM;
	case OvRendering::Settings::EInternalFormat::RGB10_A2: return GL_RGB10_A2;
	case OvRendering::Settings::EInternalFormat::RGB10_A2UI: return GL_RGB10_A2UI;
	case OvRendering::Settings::EInternalFormat::RGBA12: return GL_RGBA12;
	case OvRendering::Settings::EInternalFormat::RGBA16: return GL_RGBA16;
	case OvRendering::Settings::EInternalFormat::SRGB8: return GL_SRGB8;
	case OvRendering::Settings::EInternalFormat::SRGB8_ALPHA8: return GL_SRGB8_ALPHA8;
	case OvRendering::Settings::EInternalFormat::R16F: return GL_R16F;
	case OvRendering::Settings::EInternalFormat::RG16F: return GL_RG16F;
	case OvRendering::Settings::EInternalFormat::RGB16F: return GL_RGB16F;
	case OvRendering::Settings::EInternalFormat::RGBA16F: return GL_RGBA16F;
	case OvRendering::Settings::EInternalFormat::R32F: return GL_R32F;
	case OvRendering::Settings::EInternalFormat::RG32F: return GL_RG32F;
	case OvRendering::Settings::EInternalFormat::RGB32F: return GL_RGB32F;
	case OvRendering::Settings::EInternalFormat::RGBA32F: return GL_RGBA32F;
	case OvRendering::Settings::EInternalFormat::R11F_G11F_B10F: return GL_R11F_G11F_B10F;
	case OvRendering::Settings::EInternalFormat::RGB9_E5: return GL_RGB9_E5;
	case OvRendering::Settings::EInternalFormat::R8I: return GL_R8I;
	case OvRendering::Settings::EInternalFormat::R8UI: return GL_R8UI;
	case OvRendering::Settings::EInternalFormat::R16I: return GL_R16I;
	case OvRendering::Settings::EInternalFormat::R16UI: return GL_R16UI;
	case OvRendering::Settings::EInternalFormat::R32I: return GL_R32I;
	case OvRendering::Settings::EInternalFormat::R32UI: return GL_R32UI;
	case OvRendering::Settings::EInternalFormat::RG8I: return GL_RG8I;
	case OvRendering::Settings::EInternalFormat::RG8UI: return GL_RG8UI;
	case OvRendering::Settings::EInternalFormat::RG16I: return GL_RG16I;
	case OvRendering::Settings::EInternalFormat::RG16UI: return GL_RG16UI;
	case OvRendering::Settings::EInternalFormat::RG32I: return GL_RG32I;
	case OvRendering::Settings::EInternalFormat::RG32UI: return GL_RG32UI;
	case OvRendering::Settings::EInternalFormat::RGB8I: return GL_RGB8I;
	case OvRendering::Settings::EInternalFormat::RGB8UI: return GL_RGB8UI;
	case OvRendering::Settings::EInternalFormat::RGB16I: return GL_RGB16I;
	case OvRendering::Settings::EInternalFormat::RGB16UI: return GL_RGB16UI;
	case OvRendering::Settings::EInternalFormat::RGB32I: return GL_RGB32I;
	case OvRendering::Settings::EInternalFormat::RGB32UI: return GL_RGB32UI;
	case OvRendering::Settings::EInternalFormat::RGBA8I: return GL_RGBA8I;
	case OvRendering::Settings::EInternalFormat::RGBA8UI: return GL_RGBA8UI;
	case OvRendering::Settings::EInternalFormat::RGBA16I: return GL_RGBA16I;
	case OvRendering::Settings::EInternalFormat::RGBA16UI: return GL_RGBA16UI;
	case OvRendering::Settings::EInternalFormat::RGBA32I: return GL_RGBA32I;
	case OvRendering::Settings::EInternalFormat::RGBA32UI: return GL_RGBA32UI;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RED: return GL_COMPRESSED_RED;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RG: return GL_COMPRESSED_RG;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RGB: return GL_COMPRESSED_RGB;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RGBA: return GL_COMPRESSED_RGBA;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_SRGB: return GL_COMPRESSED_SRGB;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_SRGB_ALPHA: return GL_COMPRESSED_SRGB_ALPHA;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RED_RGTC1: return GL_COMPRESSED_RED_RGTC1;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_SIGNED_RED_RGTC1: return GL_COMPRESSED_SIGNED_RED_RGTC1;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RG_RGTC2: return GL_COMPRESSED_RG_RGTC2;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_SIGNED_RG_RGTC2: return GL_COMPRESSED_SIGNED_RG_RGTC2;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RGBA_BPTC_UNORM: return GL_COMPRESSED_RGBA_BPTC_UNORM;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_SRGB_ALPHA_BPTC_UNORM: return GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RGB_BPTC_SIGNED_FLOAT: return GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT;
	case OvRendering::Settings::EInternalFormat::COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT: return GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::EPixelDataType value)
{
	switch (value)
	{
	case OvRendering::Settings::EPixelDataType::BYTE: return GL_BYTE;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_BYTE: return GL_UNSIGNED_BYTE;
	case OvRendering::Settings::EPixelDataType::BITMAP: return GL_BITMAP;
	case OvRendering::Settings::EPixelDataType::SHORT: return GL_SHORT;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_SHORT: return GL_UNSIGNED_SHORT;
	case OvRendering::Settings::EPixelDataType::INT: return GL_INT;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_INT: return GL_UNSIGNED_INT;
	case OvRendering::Settings::EPixelDataType::FLOAT: return GL_FLOAT;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_BYTE_3_3_2: return GL_UNSIGNED_BYTE_3_3_2;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_BYTE_2_3_3_REV: return GL_UNSIGNED_BYTE_2_3_3_REV;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_SHORT_5_6_5: return GL_UNSIGNED_SHORT_5_6_5;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_SHORT_5_6_5_REV: return GL_UNSIGNED_SHORT_5_6_5_REV;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_SHORT_4_4_4_4: return GL_UNSIGNED_SHORT_4_4_4_4;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_SHORT_4_4_4_4_REV: return GL_UNSIGNED_SHORT_4_4_4_4_REV;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_SHORT_5_5_5_1: return GL_UNSIGNED_SHORT_5_5_5_1;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_SHORT_1_5_5_5_REV: return GL_UNSIGNED_SHORT_1_5_5_5_REV;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_INT_8_8_8_8: return GL_UNSIGNED_INT_8_8_8_8;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_INT_8_8_8_8_REV: return GL_UNSIGNED_INT_8_8_8_8_REV;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_INT_10_10_10_2: return GL_UNSIGNED_INT_10_10_10_2;
	case OvRendering::Settings::EPixelDataType::UNSIGNED_INT_2_10_10_10_REV: return GL_UNSIGNED_INT_2_10_10_10_REV;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::ETextureFilteringMode value)
{
	switch (value)
	{
	case OvRendering::Settings::ETextureFilteringMode::NEAREST: return GL_NEAREST;
	case OvRendering::Settings::ETextureFilteringMode::LINEAR: return GL_LINEAR;
	case OvRendering::Settings::ETextureFilteringMode::NEAREST_MIPMAP_NEAREST: return GL_NEAREST_MIPMAP_NEAREST;
	case OvRendering::Settings::ETextureFilteringMode::LINEAR_MIPMAP_LINEAR: return GL_LINEAR_MIPMAP_LINEAR;
	case OvRendering::Settings::ETextureFilteringMode::LINEAR_MIPMAP_NEAREST: return GL_LINEAR_MIPMAP_NEAREST;
	case OvRendering::Settings::ETextureFilteringMode::NEAREST_MIPMAP_LINEAR: return GL_NEAREST_MIPMAP_LINEAR;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::ETextureWrapMode value)
{
	switch (value)
	{
	case OvRendering::Settings::ETextureWrapMode::REPEAT: return GL_REPEAT;
	case OvRendering::Settings::ETextureWrapMode::CLAMP_TO_EDGE: return GL_CLAMP_TO_EDGE;
	case OvRendering::Settings::ETextureWrapMode::CLAMP_TO_BORDER: return GL_CLAMP_TO_BORDER;
	case OvRendering::Settings::ETextureWrapMode::MIRRORED_REPEAT: return GL_MIRRORED_REPEAT;
	case OvRendering::Settings::ETextureWrapMode::MIRROR_CLAMP_TO_EDGE: return GL_MIRROR_CLAMP_TO_EDGE;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::EPixelDataFormat value)
{
	switch (value)
	{
	case OvRendering::Settings::EPixelDataFormat::COLOR_INDEX: return GL_COLOR_INDEX;
	case OvRendering::Settings::EPixelDataFormat::STENCIL_INDEX: return GL_STENCIL_INDEX;
	case OvRendering::Settings::EPixelDataFormat::DEPTH_COMPONENT: return GL_DEPTH_COMPONENT;
	case OvRendering::Settings::EPixelDataFormat::RED: return GL_RED;
	case OvRendering::Settings::EPixelDataFormat::GREEN: return GL_GREEN;
	case OvRendering::Settings::EPixelDataFormat::BLUE: return GL_BLUE;
	case OvRendering::Settings::EPixelDataFormat::ALPHA: return GL_ALPHA;
	case OvRendering::Settings::EPixelDataFormat::RGB: return GL_RGB;
	case OvRendering::Settings::EPixelDataFormat::BGR: return GL_BGR;
	case OvRendering::Settings::EPixelDataFormat::RGBA: return GL_RGBA;
	case OvRendering::Settings::EPixelDataFormat::BGRA: return GL_BGRA;
	case OvRendering::Settings::EPixelDataFormat::LUMINANCE: return GL_LUMINANCE;
	case OvRendering::Settings::EPixelDataFormat::LUMINANCE_ALPHA: return GL_LUMINANCE_ALPHA;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::EDataType value)
{
	switch (value)
	{
	case OvRendering::Settings::EDataType::BYTE: return GL_BYTE;
	case OvRendering::Settings::EDataType::UNSIGNED_BYTE: return GL_UNSIGNED_BYTE;
	case OvRendering::Settings::EDataType::SHORT: return GL_SHORT;
	case OvRendering::Settings::EDataType::UNSIGNED_SHORT: return GL_UNSIGNED_SHORT;
	case OvRendering::Settings::EDataType::INT: return GL_INT;
	case OvRendering::Settings::EDataType::UNSIGNED_INT: return GL_UNSIGNED_INT;
	case OvRendering::Settings::EDataType::FLOAT: return GL_FLOAT;
	case OvRendering::Settings::EDataType::DOUBLE: return GL_DOUBLE;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::EAccessSpecifier value)
{
	switch (value)
	{
	case OvRendering::Settings::EAccessSpecifier::STREAM_DRAW: return GL_STREAM_DRAW;
	case OvRendering::Settings::EAccessSpecifier::STREAM_READ: return GL_STREAM_READ;
	case OvRendering::Settings::EAccessSpecifier::STREAM_COPY: return GL_STREAM_COPY;
	case OvRendering::Settings::EAccessSpecifier::DYNAMIC_DRAW: return GL_DYNAMIC_DRAW;
	case OvRendering::Settings::EAccessSpecifier::DYNAMIC_READ: return GL_DYNAMIC_READ;
	case OvRendering::Settings::EAccessSpecifier::DYNAMIC_COPY: return GL_DYNAMIC_COPY;
	case OvRendering::Settings::EAccessSpecifier::STATIC_DRAW: return GL_STATIC_DRAW;
	case OvRendering::Settings::EAccessSpecifier::STATIC_READ: return GL_STATIC_READ;
	case OvRendering::Settings::EAccessSpecifier::STATIC_COPY: return GL_STATIC_COPY;
	}
	return {};
}

constexpr GLenum ToGLenum(OvRendering::Settings::UniformType value)
{
	switch (value)
	{
	case OvRendering::Settings::UniformType::UNIFORM_BOOL: return GL_BOOL;
	case OvRendering::Settings::UniformType::UNIFORM_INT: return GL_INT;
	case OvRendering::Settings::UniformType::UNIFORM_FLOAT: return GL_FLOAT;
	case OvRendering::Settings::UniformType::UNIFORM_FLOAT_VEC2: return GL_FLOAT_VEC2;
	case OvRendering::Settings::UniformType::UNIFORM_FLOAT_VEC3: return GL_FLOAT_VEC3;
	case OvRendering::Settings::UniformType::UNIFORM_FLOAT_VEC4: return GL_FLOAT_VEC4;
	case OvRendering::Settings::UniformType::UNIFORM_FLOAT_MAT4: return GL_FLOAT_MAT4;
	case OvRendering::Settings::UniformType::UNIFORM_DOUBLE_MAT4: return GL_DOUBLE_MAT4;
	case OvRendering::Settings::UniformType::UNIFORM_SAMPLER_2D: return GL_SAMPLER_2D;
	case OvRendering::Settings::UniformType::UNIFORM_SAMPLER_CUBE: return GL_SAMPLER_CUBE;
	}
	return {};
}

constexpr OvRendering::Settings::UniformType FromGLenum(GLenum value)
{
	switch (value)
	{
	case GL_BOOL: return OvRendering::Settings::UniformType::UNIFORM_BOOL;
	case GL_INT: return OvRendering::Settings::UniformType::UNIFORM_INT;
	case GL_FLOAT: return OvRendering::Settings::UniformType::UNIFORM_FLOAT;
	case GL_FLOAT_VEC2: return OvRendering::Settings::UniformType::UNIFORM_FLOAT_VEC2;
	case GL_FLOAT_VEC3: return OvRendering::Settings::UniformType::UNIFORM_FLOAT_VEC3;
	case GL_FLOAT_VEC4: return OvRendering::Settings::UniformType::UNIFORM_FLOAT_VEC4;
	case GL_FLOAT_MAT4: return OvRendering::Settings::UniformType::UNIFORM_FLOAT_MAT4;
	case GL_DOUBLE_MAT4: return OvRendering::Settings::UniformType::UNIFORM_DOUBLE_MAT4;
	case GL_SAMPLER_2D: return OvRendering::Settings::UniformType::UNIFORM_SAMPLER_2D;
	case GL_SAMPLER_CUBE: return OvRendering::Settings::UniformType::UNIFORM_SAMPLER_CUBE;
	}
	return {};
}
