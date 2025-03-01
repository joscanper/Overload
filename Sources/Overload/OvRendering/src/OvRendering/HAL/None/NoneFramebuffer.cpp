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
OvRendering::HAL::NoneFramebuffer::TFramebuffer()
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

bool OvRendering::HAL::NoneFramebuffer::Validate()
{
	return m_context.valid = true;
}

template<>
bool OvRendering::HAL::NoneFramebuffer::IsValid() const
{
	return m_context.valid;
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
void OvRendering::HAL::NoneFramebuffer::Resize(uint16_t p_width, uint16_t p_height)
{
	OVASSERT(IsValid(), "Invalid framebuffer");
}

template<>
void OvRendering::HAL::NoneFramebuffer::SetTargetDrawBuffer(std::optional<uint32_t> p_index)
{
	OVASSERT(IsValid(), "Invalid framebuffer");
}

template<>
void OvRendering::HAL::NoneFramebuffer::SetTargetReadBuffer(std::optional<uint32_t> p_index)
{
	OVASSERT(IsValid(), "Invalid framebuffer");
}

template<>
uint32_t OvRendering::HAL::NoneFramebuffer::GetID() const
{
	return 0;
}

template<>
std::pair<uint16_t, uint16_t> OvRendering::HAL::NoneFramebuffer::GetSize(Settings::EFramebufferAttachment p_attachment) const
{
	return { {}, {} }; // <-- I swear it's not an emoji
}

template<>
void OvRendering::HAL::NoneFramebuffer::BlitToBackBuffer(uint16_t p_backBufferWidth, uint16_t p_backBufferHeight) const
{
	OVASSERT(IsValid(), "Cannot blit an invalid framebuffer");
}

template<>
void OvRendering::HAL::NoneFramebuffer::ReadPixels(
	uint32_t p_x,
	uint32_t p_y,
	uint32_t p_width,
	uint32_t p_height,
	Settings::EPixelDataFormat p_format,
	Settings::EPixelDataType p_type,
	void* p_data) const
{
	OVASSERT(IsValid(), "Cannot read pixels from an invalid framebuffer");
}
