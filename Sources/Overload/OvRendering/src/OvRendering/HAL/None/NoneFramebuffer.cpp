/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvDebug/Assertion.h>
#include <OvRendering/HAL/None/NoneFramebuffer.h>
#include <OvRendering/HAL/None/NoneRenderbuffer.h>

template<>
template<>
void OvRendering::HAL::NoneFramebuffer::Attach(std::shared_ptr<NoneRenderbuffer> p_toAttach, Settings::EFramebufferAttachment p_attachment, uint32_t p_index)
{
	OVASSERT(p_toAttach != nullptr, "Cannot attach a null renderbuffer");
}

template<>
template<>
void OvRendering::HAL::NoneFramebuffer::Attach(std::shared_ptr<NoneTexture> p_toAttach, Settings::EFramebufferAttachment p_attachment, uint32_t p_index)
{
	OVASSERT(p_toAttach != nullptr, "Cannot attach a null texture");
}

template<>
OvRendering::HAL::NoneFramebuffer::TFramebuffer(uint16_t p_width, uint16_t p_height, bool p_depthOnly) :
	m_context{
		.width = p_width,
		.height = p_height,
		.depthOnly = p_depthOnly
}
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
template<>
OvTools::Utils::OptRef<OvRendering::HAL::NoneTexture> OvRendering::HAL::NoneFramebuffer::GetAttachment(OvRendering::Settings::EFramebufferAttachment p_attachment, uint32_t p_index) const
{
	static NoneTexture noneTexture;
	return noneTexture;
}

template<>
template<>
OvTools::Utils::OptRef<OvRendering::HAL::NoneRenderbuffer> OvRendering::HAL::NoneFramebuffer::GetAttachment(OvRendering::Settings::EFramebufferAttachment p_attachment, uint32_t p_index) const
{
	static NoneRenderbuffer noneRenderbuffer;
	return noneRenderbuffer;
}

template<>
void OvRendering::HAL::NoneFramebuffer::Resize(uint16_t p_width, uint16_t p_height, bool p_forceUpdate)
{
	m_context.width = p_width;
	m_context.height = p_height;
}

template<>
uint32_t OvRendering::HAL::NoneFramebuffer::GetID() const
{
	return 0;
}

template<>
uint16_t OvRendering::HAL::NoneFramebuffer::GetWidth() const
{
	return m_context.width;
}

template<>
uint16_t OvRendering::HAL::NoneFramebuffer::GetHeight() const
{
	return m_context.height;
}

template<>
void OvRendering::HAL::NoneFramebuffer::BlitToBackBuffer(uint16_t p_backBufferWidth, uint16_t p_backBufferHeight) const
{
}
