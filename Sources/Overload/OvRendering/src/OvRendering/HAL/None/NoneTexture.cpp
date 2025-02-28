/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvDebug/Assertion.h>

#include <OvRendering/HAL/None//NoneTexture.h>

template<>
OvRendering::HAL::NoneTexture::TTexture()
{
}

template<>
OvRendering::HAL::NoneTexture::~TTexture()
{
}

template<>
void OvRendering::HAL::NoneTexture::Allocate(const Settings::TextureDesc& p_desc)
{
	m_textureContext.desc = p_desc;
	m_textureContext.allocated = true;
}

template<>
bool OvRendering::HAL::NoneTexture::IsValid() const
{
	return m_textureContext.allocated;
}

template<>
bool OvRendering::HAL::NoneTexture::IsMutable() const
{
	OVASSERT(IsValid(), "Cannot check if a texture is mutable before it's allocated");
	return m_textureContext.desc.mutableDesc.has_value();
}

template<>
void OvRendering::HAL::NoneTexture::Upload(void* p_data, Settings::EFormat p_format, Settings::EPixelDataType p_type)
{
	OVASSERT(IsValid(), "Cannot upload data to a non-allocated texture");

	if (IsMutable())
	{
		auto& mutableDesc = m_textureContext.desc.mutableDesc.value();
		mutableDesc.format = p_format;
		mutableDesc.type = p_type;
	}
}

template<>
void OvRendering::HAL::NoneTexture::Resize(uint32_t p_width, uint32_t p_height)
{
	OVASSERT(IsValid(), "Cannot resize non-allocated texture");
	OVASSERT(!IsMutable(), "Cannot resize a mutable texture");
}

template<>
const OvRendering::Settings::TextureDesc& OvRendering::HAL::NoneTexture::GetDesc() const
{
	OVASSERT(IsValid(), "Cannot get desc of non-allocated texture");
	return m_textureContext.desc;
}

template<>
void OvRendering::HAL::NoneTexture::GenerateMipMaps() const
{
	OVASSERT(IsValid(), "Cannot generate mipmaps for a non-allocated texture");
}

template<>
void OvRendering::HAL::NoneTexture::SetBorderColor(const OvMaths::FVector4& p_color)
{
	OVASSERT(IsValid(), "Cannot set border color of a non-allocated texture");
	OVASSERT(m_textureContext.desc.internalFormat == Settings::EInternalFormat::RGBA32F, "Cannot set border color of a non-RGBA32F texture");
}
