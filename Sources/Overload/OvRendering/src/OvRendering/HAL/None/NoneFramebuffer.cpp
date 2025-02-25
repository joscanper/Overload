/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneFramebuffer.h>
#include <OvRendering/HAL/None/NoneTextureHandle.h>

template<>
OvRendering::HAL::NoneFramebuffer::TFramebuffer(uint16_t p_width, uint16_t p_height, bool p_depthOnly)
{
}

template<>
OvRendering::HAL::NoneFramebuffer::~TFramebuffer()
{
}

template<>
void OvRendering::HAL::NoneFramebuffer::Bind() const
{
}

template<>
void OvRendering::HAL::NoneFramebuffer::Unbind() const
{
}

template<>
void OvRendering::HAL::NoneFramebuffer::Resize(uint16_t p_width, uint16_t p_height, bool p_forceUpdate)
{
}

template<>
uint32_t OvRendering::HAL::NoneFramebuffer::GetID() const
{
	return 0;
}

template<>
uint32_t OvRendering::HAL::NoneFramebuffer::GetTextureID() const
{
	return 0;
}

template<>
OvRendering::HAL::NoneTextureHandle OvRendering::HAL::NoneFramebuffer::GetTexture() const
{
	return NoneTextureHandle{};
}

template<>
uint32_t OvRendering::HAL::NoneFramebuffer::GetRenderBufferID() const
{
	return 0;
}

template<>
uint16_t OvRendering::HAL::NoneFramebuffer::GetWidth() const
{
	return 1;
}

template<>
uint16_t OvRendering::HAL::NoneFramebuffer::GetHeight() const
{
	return 1;
}

template<>
void OvRendering::HAL::NoneFramebuffer::GenerateMipMaps() const
{
}

template<>
void OvRendering::HAL::NoneFramebuffer::BlitToBackBuffer(uint16_t p_backBufferWidth, uint16_t p_backBufferHeight) const
{
}
