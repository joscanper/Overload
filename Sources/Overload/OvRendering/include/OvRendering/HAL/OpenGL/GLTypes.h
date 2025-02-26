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
#include <OvTools/Utils/EnumMapper.h>

namespace OvRendering::Settings
{
	template <>
	struct MappingFor<EComparaisonAlgorithm, GLenum> {
		using type = std::tuple<
			EnumValuePair<EComparaisonAlgorithm::NEVER, GL_NEVER>,
			EnumValuePair<EComparaisonAlgorithm::LESS, GL_LESS>,
			EnumValuePair<EComparaisonAlgorithm::EQUAL, GL_EQUAL>,
			EnumValuePair<EComparaisonAlgorithm::LESS_EQUAL, GL_LEQUAL>,
			EnumValuePair<EComparaisonAlgorithm::GREATER, GL_GREATER>,
			EnumValuePair<EComparaisonAlgorithm::NOTEQUAL, GL_NOTEQUAL>,
			EnumValuePair<EComparaisonAlgorithm::GREATER_EQUAL, GL_GEQUAL>,
			EnumValuePair<EComparaisonAlgorithm::ALWAYS, GL_ALWAYS>
		>;
	};

	template <>
	struct MappingFor<ERasterizationMode, GLenum> {
		using type = std::tuple<
			EnumValuePair<ERasterizationMode::POINT, GL_POINT>,
			EnumValuePair<ERasterizationMode::LINE, GL_LINE>,
			EnumValuePair<ERasterizationMode::FILL, GL_FILL>
		>;
	};

	template <>
	struct MappingFor<ECullFace, GLenum> {
		using type = std::tuple<
			EnumValuePair<ECullFace::FRONT, GL_FRONT>,
			EnumValuePair<ECullFace::BACK, GL_BACK>,
			EnumValuePair<ECullFace::FRONT_AND_BACK, GL_FRONT_AND_BACK>
		>;
	};

	template <>
	struct MappingFor<EOperation, GLenum> {
		using type = std::tuple<
			EnumValuePair<EOperation::KEEP, GL_KEEP>,
			EnumValuePair<EOperation::ZERO, GL_ZERO>,
			EnumValuePair<EOperation::REPLACE, GL_REPLACE>,
			EnumValuePair<EOperation::INCREMENT, GL_INCR>,
			EnumValuePair<EOperation::INCREMENT_WRAP, GL_INCR_WRAP>,
			EnumValuePair<EOperation::DECREMENT, GL_DECR>,
			EnumValuePair<EOperation::DECREMENT_WRAP, GL_DECR_WRAP>,
			EnumValuePair<EOperation::INVERT, GL_INVERT>
		>;
	};

	template <>
	struct MappingFor<ERenderingCapability, GLenum> {
		using type = std::tuple<
			EnumValuePair<ERenderingCapability::BLEND, GL_BLEND>,
			EnumValuePair<ERenderingCapability::CULL_FACE, GL_CULL_FACE>,
			EnumValuePair<ERenderingCapability::DEPTH_TEST, GL_DEPTH_TEST>,
			EnumValuePair<ERenderingCapability::DITHER, GL_DITHER>,
			EnumValuePair<ERenderingCapability::POLYGON_OFFSET_FILL, GL_POLYGON_OFFSET_FILL>,
			EnumValuePair<ERenderingCapability::SAMPLE_ALPHA_TO_COVERAGE, GL_SAMPLE_ALPHA_TO_COVERAGE>,
			EnumValuePair<ERenderingCapability::SAMPLE_COVERAGE, GL_SAMPLE_COVERAGE>,
			EnumValuePair<ERenderingCapability::SCISSOR_TEST, GL_SCISSOR_TEST>,
			EnumValuePair<ERenderingCapability::STENCIL_TEST, GL_STENCIL_TEST>,
			EnumValuePair<ERenderingCapability::MULTISAMPLE, GL_MULTISAMPLE>
		>;
	};

	template <>
	struct MappingFor<EPrimitiveMode, GLenum> {
		using type = std::tuple<
			EnumValuePair<EPrimitiveMode::POINTS, GL_POINTS>,
			EnumValuePair<EPrimitiveMode::LINES, GL_LINES>,
			EnumValuePair<EPrimitiveMode::LINE_LOOP, GL_LINE_LOOP>,
			EnumValuePair<EPrimitiveMode::LINE_STRIP, GL_LINE_STRIP>,
			EnumValuePair<EPrimitiveMode::TRIANGLES, GL_TRIANGLES>,
			EnumValuePair<EPrimitiveMode::TRIANGLE_STRIP, GL_TRIANGLE_STRIP>,
			EnumValuePair<EPrimitiveMode::TRIANGLE_FAN, GL_TRIANGLE_FAN>,
			EnumValuePair<EPrimitiveMode::LINES_ADJACENCY, GL_LINES_ADJACENCY>,
			EnumValuePair<EPrimitiveMode::LINE_STRIP_ADJACENCY, GL_LINE_STRIP_ADJACENCY>,
			EnumValuePair<EPrimitiveMode::PATCHES, GL_PATCHES>
		>;
	};

	template <>
	struct MappingFor<EFormat, GLenum> {
		using type = std::tuple<
			EnumValuePair<EFormat::RED, GL_RED>,
			EnumValuePair<EFormat::RG, GL_RG>,
			EnumValuePair<EFormat::RGB, GL_RGB>,
			EnumValuePair<EFormat::BGR, GL_BGR>,
			EnumValuePair<EFormat::RGBA, GL_RGBA>,
			EnumValuePair<EFormat::BGRA, GL_BGRA>,
			EnumValuePair<EFormat::RED_INTEGER, GL_RED_INTEGER>,
			EnumValuePair<EFormat::RG_INTEGER, GL_RG_INTEGER>,
			EnumValuePair<EFormat::RGB_INTEGER, GL_RGB_INTEGER>,
			EnumValuePair<EFormat::BGR_INTEGER, GL_BGR_INTEGER>,
			EnumValuePair<EFormat::RGBA_INTEGER, GL_RGBA_INTEGER>,
			EnumValuePair<EFormat::BGRA_INTEGER, GL_BGRA_INTEGER>,
			EnumValuePair<EFormat::STENCIL_INDEX, GL_STENCIL_INDEX>,
			EnumValuePair<EFormat::DEPTH_COMPONENT, GL_DEPTH_COMPONENT>,
			EnumValuePair<EFormat::DEPTH_STENCIL, GL_DEPTH_STENCIL>
		>;
	};

	template <>
	struct MappingFor<ETextureFilteringMode, GLenum> {
		using type = std::tuple<
			EnumValuePair<ETextureFilteringMode::NEAREST, GL_NEAREST>,
			EnumValuePair<ETextureFilteringMode::LINEAR, GL_LINEAR>,
			EnumValuePair<ETextureFilteringMode::NEAREST_MIPMAP_NEAREST, GL_NEAREST_MIPMAP_NEAREST>,
			EnumValuePair<ETextureFilteringMode::LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR>,
			EnumValuePair<ETextureFilteringMode::LINEAR_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_NEAREST>,
			EnumValuePair<ETextureFilteringMode::NEAREST_MIPMAP_LINEAR, GL_NEAREST_MIPMAP_LINEAR>
		>;
	};

	template <>
	struct MappingFor<ETextureWrapMode, GLenum> {
		using type = std::tuple<
			EnumValuePair<ETextureWrapMode::REPEAT, GL_REPEAT>,
			EnumValuePair<ETextureWrapMode::CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE>,
			EnumValuePair<ETextureWrapMode::CLAMP_TO_BORDER, GL_CLAMP_TO_BORDER>,
			EnumValuePair<ETextureWrapMode::MIRRORED_REPEAT, GL_MIRRORED_REPEAT>,
			EnumValuePair<ETextureWrapMode::MIRROR_CLAMP_TO_EDGE, GL_MIRROR_CLAMP_TO_EDGE>
		>;
	};

	template <>
	struct MappingFor<EPixelDataFormat, GLenum> {
		using type = std::tuple<
			EnumValuePair<EPixelDataFormat::COLOR_INDEX, GL_COLOR_INDEX>,
			EnumValuePair<EPixelDataFormat::STENCIL_INDEX, GL_STENCIL_INDEX>,
			EnumValuePair<EPixelDataFormat::DEPTH_COMPONENT, GL_DEPTH_COMPONENT>,
			EnumValuePair<EPixelDataFormat::RED, GL_RED>,
			EnumValuePair<EPixelDataFormat::GREEN, GL_GREEN>,
			EnumValuePair<EPixelDataFormat::BLUE, GL_BLUE>,
			EnumValuePair<EPixelDataFormat::ALPHA, GL_ALPHA>,
			EnumValuePair<EPixelDataFormat::RGB, GL_RGB>,
			EnumValuePair<EPixelDataFormat::BGR, GL_BGR>,
			EnumValuePair<EPixelDataFormat::RGBA, GL_RGBA>,
			EnumValuePair<EPixelDataFormat::BGRA, GL_BGRA>,
			EnumValuePair<EPixelDataFormat::LUMINANCE, GL_LUMINANCE>,
			EnumValuePair<EPixelDataFormat::LUMINANCE_ALPHA, GL_LUMINANCE_ALPHA>
		>;
	};

	template <>
	struct MappingFor<EPixelDataType, GLenum> {
		using type = std::tuple <
			EnumValuePair<EPixelDataType::BYTE, GL_BYTE>,
			EnumValuePair<EPixelDataType::UNSIGNED_BYTE, GL_UNSIGNED_BYTE>,
			EnumValuePair<EPixelDataType::BITMAP, GL_BITMAP>,
			EnumValuePair<EPixelDataType::SHORT, GL_SHORT>,
			EnumValuePair<EPixelDataType::UNSIGNED_SHORT, GL_UNSIGNED_SHORT>,
			EnumValuePair<EPixelDataType::INT, GL_INT>,
			EnumValuePair<EPixelDataType::UNSIGNED_INT, GL_UNSIGNED_INT>,
			EnumValuePair<EPixelDataType::FLOAT, GL_FLOAT>,
			EnumValuePair<EPixelDataType::UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_3_3_2>,
			EnumValuePair<EPixelDataType::UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_BYTE_2_3_3_REV>,
			EnumValuePair<EPixelDataType::UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5>,
			EnumValuePair<EPixelDataType::UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_5_6_5_REV>,
			EnumValuePair<EPixelDataType::UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4>,
			EnumValuePair<EPixelDataType::UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_4_4_4_4_REV>,
			EnumValuePair<EPixelDataType::UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_5_5_5_1>,
			EnumValuePair<EPixelDataType::UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_SHORT_1_5_5_5_REV>,
			EnumValuePair<EPixelDataType::UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8>,
			EnumValuePair<EPixelDataType::UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_8_8_8_8_REV>,
			EnumValuePair<EPixelDataType::UNSIGNED_INT_10_10_10_2, GL_UNSIGNED_INT_10_10_10_2>,
			EnumValuePair<EPixelDataType::UNSIGNED_INT_2_10_10_10_REV, GL_UNSIGNED_INT_2_10_10_10_REV>
		> ;
	};

	template <>
	struct MappingFor<EDataType, GLenum> {
		using type = std::tuple<
			EnumValuePair<EDataType::BYTE, GL_BYTE>,
			EnumValuePair<EDataType::UNSIGNED_BYTE, GL_UNSIGNED_BYTE>,
			EnumValuePair<EDataType::SHORT, GL_SHORT>,
			EnumValuePair<EDataType::UNSIGNED_SHORT, GL_UNSIGNED_SHORT>,
			EnumValuePair<EDataType::INT, GL_INT>,
			EnumValuePair<EDataType::UNSIGNED_INT, GL_UNSIGNED_INT>,
			EnumValuePair<EDataType::FLOAT, GL_FLOAT>,
			EnumValuePair<EDataType::DOUBLE, GL_DOUBLE>
		>;
	};

	template <>
	struct MappingFor<EAccessSpecifier, GLenum> {
		using type = std::tuple<
			EnumValuePair<EAccessSpecifier::STREAM_DRAW, GL_STREAM_DRAW>,
			EnumValuePair<EAccessSpecifier::STREAM_READ, GL_STREAM_READ>,
			EnumValuePair<EAccessSpecifier::STREAM_COPY, GL_STREAM_COPY>,
			EnumValuePair<EAccessSpecifier::DYNAMIC_DRAW, GL_DYNAMIC_DRAW>,
			EnumValuePair<EAccessSpecifier::DYNAMIC_READ, GL_DYNAMIC_READ>,
			EnumValuePair<EAccessSpecifier::DYNAMIC_COPY, GL_DYNAMIC_COPY>,
			EnumValuePair<EAccessSpecifier::STATIC_DRAW, GL_STATIC_DRAW>,
			EnumValuePair<EAccessSpecifier::STATIC_READ, GL_STATIC_READ>,
			EnumValuePair<EAccessSpecifier::STATIC_COPY, GL_STATIC_COPY>
		>;
	};

	template <>
	struct MappingFor<UniformType, GLenum> {
		using type = std::tuple<
			EnumValuePair<UniformType::UNIFORM_BOOL, GL_BOOL>,
			EnumValuePair<UniformType::UNIFORM_INT, GL_INT>,
			EnumValuePair<UniformType::UNIFORM_FLOAT, GL_FLOAT>,
			EnumValuePair<UniformType::UNIFORM_FLOAT_VEC2, GL_FLOAT_VEC2>,
			EnumValuePair<UniformType::UNIFORM_FLOAT_VEC3, GL_FLOAT_VEC3>,
			EnumValuePair<UniformType::UNIFORM_FLOAT_VEC4, GL_FLOAT_VEC4>,
			EnumValuePair<UniformType::UNIFORM_FLOAT_MAT4, GL_FLOAT_MAT4>,
			EnumValuePair<UniformType::UNIFORM_DOUBLE_MAT4, GL_DOUBLE_MAT4>,
			EnumValuePair<UniformType::UNIFORM_SAMPLER_2D, GL_SAMPLER_2D>,
			EnumValuePair<UniformType::UNIFORM_SAMPLER_CUBE, GL_SAMPLER_CUBE>
		>;
	};

	// Internal format has a large number of enums, so including it here as well
	template <>
	struct MappingFor<EInternalFormat, GLenum> {
		using type = std::tuple <
			EnumValuePair<EInternalFormat::DEPTH_COMPONENT, GL_DEPTH_COMPONENT>,
			EnumValuePair<EInternalFormat::DEPTH_STENCIL, GL_DEPTH_STENCIL>,
			EnumValuePair<EInternalFormat::RED, GL_RED>,
			EnumValuePair<EInternalFormat::RG, GL_RG>,
			EnumValuePair<EInternalFormat::RGB, GL_RGB>,
			EnumValuePair<EInternalFormat::RGBA, GL_RGBA>,
			EnumValuePair<EInternalFormat::R8, GL_R8>,
			EnumValuePair<EInternalFormat::R8_SNORM, GL_R8_SNORM>,
			EnumValuePair<EInternalFormat::R16, GL_R16>,
			EnumValuePair<EInternalFormat::R16_SNORM, GL_R16_SNORM>,
			EnumValuePair<EInternalFormat::RG8, GL_RG8>,
			EnumValuePair<EInternalFormat::RG8_SNORM, GL_RG8_SNORM>,
			EnumValuePair<EInternalFormat::RG16, GL_RG16>,
			EnumValuePair<EInternalFormat::RG16_SNORM, GL_RG16_SNORM>,
			EnumValuePair<EInternalFormat::R3_G3_B2, GL_R3_G3_B2>,
			EnumValuePair<EInternalFormat::RGB4, GL_RGB4>,
			EnumValuePair<EInternalFormat::RGB5, GL_RGB5>,
			EnumValuePair<EInternalFormat::RGB8, GL_RGB8>,
			EnumValuePair<EInternalFormat::RGB8_SNORM, GL_RGB8_SNORM>,
			EnumValuePair<EInternalFormat::RGB10, GL_RGB10>,
			EnumValuePair<EInternalFormat::RGB12, GL_RGB12>,
			EnumValuePair<EInternalFormat::RGB16_SNORM, GL_RGB16_SNORM>,
			EnumValuePair<EInternalFormat::RGBA2, GL_RGBA2>,
			EnumValuePair<EInternalFormat::RGBA4, GL_RGBA4>,
			EnumValuePair<EInternalFormat::RGB5_A1, GL_RGB5_A1>,
			EnumValuePair<EInternalFormat::RGBA8, GL_RGBA8>,
			EnumValuePair<EInternalFormat::RGBA8_SNORM, GL_RGBA8_SNORM>,
			EnumValuePair<EInternalFormat::RGB10_A2, GL_RGB10_A2>,
			EnumValuePair<EInternalFormat::RGB10_A2UI, GL_RGB10_A2UI>,
			EnumValuePair<EInternalFormat::RGBA12, GL_RGBA12>,
			EnumValuePair<EInternalFormat::RGBA16, GL_RGBA16>,
			EnumValuePair<EInternalFormat::SRGB8, GL_SRGB8>,
			EnumValuePair<EInternalFormat::SRGB8_ALPHA8, GL_SRGB8_ALPHA8>,
			EnumValuePair<EInternalFormat::R16F, GL_R16F>,
			EnumValuePair<EInternalFormat::RG16F, GL_RG16F>,
			EnumValuePair<EInternalFormat::RGB16F, GL_RGB16F>,
			EnumValuePair<EInternalFormat::RGBA16F, GL_RGBA16F>,
			EnumValuePair<EInternalFormat::R32F, GL_R32F>,
			EnumValuePair<EInternalFormat::RG32F, GL_RG32F>,
			EnumValuePair<EInternalFormat::RGB32F, GL_RGB32F>,
			EnumValuePair<EInternalFormat::RGBA32F, GL_RGBA32F>,
			EnumValuePair<EInternalFormat::R11F_G11F_B10F, GL_R11F_G11F_B10F>,
			EnumValuePair<EInternalFormat::RGB9_E5, GL_RGB9_E5>,
			EnumValuePair<EInternalFormat::R8I, GL_R8I>,
			EnumValuePair<EInternalFormat::R8UI, GL_R8UI>,
			EnumValuePair<EInternalFormat::R16I, GL_R16I>,
			EnumValuePair<EInternalFormat::R16UI, GL_R16UI>,
			EnumValuePair<EInternalFormat::R32I, GL_R32I>,
			EnumValuePair<EInternalFormat::R32UI, GL_R32UI>,
			EnumValuePair<EInternalFormat::RG8I, GL_RG8I>,
			EnumValuePair<EInternalFormat::RG8UI, GL_RG8UI>,
			EnumValuePair<EInternalFormat::RG16I, GL_RG16I>,
			EnumValuePair<EInternalFormat::RG16UI, GL_RG16UI>,
			EnumValuePair<EInternalFormat::RG32I, GL_RG32I>,
			EnumValuePair<EInternalFormat::RG32UI, GL_RG32UI>,
			EnumValuePair<EInternalFormat::RGB8I, GL_RGB8I>,
			EnumValuePair<EInternalFormat::RGB8UI, GL_RGB8UI>,
			EnumValuePair<EInternalFormat::RGB16I, GL_RGB16I>,
			EnumValuePair<EInternalFormat::RGB16UI, GL_RGB16UI>,
			EnumValuePair<EInternalFormat::RGB32I, GL_RGB32I>,
			EnumValuePair<EInternalFormat::RGB32UI, GL_RGB32UI>,
			EnumValuePair<EInternalFormat::RGBA8I, GL_RGBA8I>,
			EnumValuePair<EInternalFormat::RGBA8UI, GL_RGBA8UI>,
			EnumValuePair<EInternalFormat::RGBA16I, GL_RGBA16I>,
			EnumValuePair<EInternalFormat::RGBA16UI, GL_RGBA16UI>,
			EnumValuePair<EInternalFormat::RGBA32I, GL_RGBA32I>,
			EnumValuePair<EInternalFormat::RGBA32UI, GL_RGBA32UI>,
			EnumValuePair<EInternalFormat::COMPRESSED_RED, GL_COMPRESSED_RED>,
			EnumValuePair<EInternalFormat::COMPRESSED_RG, GL_COMPRESSED_RG>,
			EnumValuePair<EInternalFormat::COMPRESSED_RGB, GL_COMPRESSED_RGB>,
			EnumValuePair<EInternalFormat::COMPRESSED_RGBA, GL_COMPRESSED_RGBA>,
			EnumValuePair<EInternalFormat::COMPRESSED_SRGB, GL_COMPRESSED_SRGB>,
			EnumValuePair<EInternalFormat::COMPRESSED_SRGB_ALPHA, GL_COMPRESSED_SRGB_ALPHA>,
			EnumValuePair<EInternalFormat::COMPRESSED_RED_RGTC1, GL_COMPRESSED_RED_RGTC1>,
			EnumValuePair<EInternalFormat::COMPRESSED_SIGNED_RED_RGTC1, GL_COMPRESSED_SIGNED_RED_RGTC1>,
			EnumValuePair<EInternalFormat::COMPRESSED_RG_RGTC2, GL_COMPRESSED_RG_RGTC2>,
			EnumValuePair<EInternalFormat::COMPRESSED_SIGNED_RG_RGTC2, GL_COMPRESSED_SIGNED_RG_RGTC2>,
			EnumValuePair<EInternalFormat::COMPRESSED_RGBA_BPTC_UNORM, GL_COMPRESSED_RGBA_BPTC_UNORM>,
			EnumValuePair<EInternalFormat::COMPRESSED_SRGB_ALPHA_BPTC_UNORM, GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM>,
			EnumValuePair<EInternalFormat::COMPRESSED_RGB_BPTC_SIGNED_FLOAT, GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT>,
			EnumValuePair<EInternalFormat::COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT, GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT>
		> ;
	};
}
