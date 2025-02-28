/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvDebug/Assertion.h>
#include <OvDebug/Logger.h>
#include <OvRendering/HAL/OpenGL/GLFramebuffer.h>
#include <OvRendering/HAL/OpenGL/GLRenderbuffer.h>
#include <OvRendering/HAL/OpenGL/GLTypes.h>

template<>
template<>
void OvRendering::HAL::GLFramebuffer::Attach(std::shared_ptr<GLRenderbuffer> p_toAttach, Settings::EFramebufferAttachment p_attachment, uint32_t p_index)
{
	OVASSERT(p_toAttach != nullptr, "Cannot attach a null renderbuffer");

	const auto attachmentIndex = EnumToValue<GLenum>(p_attachment) + static_cast<GLenum>(p_index);
	Bind();
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachmentIndex, GL_RENDERBUFFER, p_toAttach->GetID());
	Unbind();
	m_context.attachments[attachmentIndex] = p_toAttach;
}

template<>
template<>
void OvRendering::HAL::GLFramebuffer::Attach(std::shared_ptr<GLTexture> p_toAttach, Settings::EFramebufferAttachment p_attachment, uint32_t p_index)
{
	OVASSERT(p_toAttach != nullptr, "Cannot attach a null texture");

	const auto attachmentIndex = EnumToValue<GLenum>(p_attachment) + static_cast<GLenum>(p_index);
	Bind();
	glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentIndex, GL_TEXTURE_2D, p_toAttach->GetID(), 0);
	Unbind();
	m_context.attachments[attachmentIndex] = p_toAttach;
}

template<>
OvRendering::HAL::GLFramebuffer::TFramebuffer()
{
	glGenFramebuffers(1, &m_context.id);
}

template<>
OvRendering::HAL::GLFramebuffer::~TFramebuffer()
{
	glDeleteFramebuffers(1, &m_context.id);
}

template<>
void OvRendering::HAL::GLFramebuffer::Bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_context.id);
}

template<>
void OvRendering::HAL::GLFramebuffer::Unbind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

bool OvRendering::HAL::GLFramebuffer::Validate()
{
	const GLenum status = glCheckNamedFramebufferStatus(m_context.id, GL_FRAMEBUFFER);

	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		OVFLOG_ERROR("Framebuffer validation failed with status: " + std::to_string(status));
		return m_context.valid = false;
	}

	return m_context.valid = true;
}

template<>
bool OvRendering::HAL::GLFramebuffer::IsValid() const
{
	return m_context.valid;
}

template<>
template<>
OvTools::Utils::OptRef<OvRendering::HAL::GLTexture> OvRendering::HAL::GLFramebuffer::GetAttachment(OvRendering::Settings::EFramebufferAttachment p_attachment, uint32_t p_index) const
{
	const auto attachmentIndex = EnumToValue<GLenum>(p_attachment) + static_cast<GLenum>(p_index);

	if (m_context.attachments.contains(attachmentIndex))
	{
		auto attachment = m_context.attachments.at(attachmentIndex);

		if (auto pval = std::get_if<std::shared_ptr<GLTexture>>(&attachment); pval && *pval)
		{
			return **pval;
		}
	}

	return std::nullopt;
}

template<>
template<>
OvTools::Utils::OptRef<OvRendering::HAL::GLRenderbuffer> OvRendering::HAL::GLFramebuffer::GetAttachment(OvRendering::Settings::EFramebufferAttachment p_attachment, uint32_t p_index) const
{
	const auto attachmentIndex = EnumToValue<GLenum>(p_attachment) + static_cast<GLenum>(p_index);

	if (m_context.attachments.contains(attachmentIndex))
	{
		auto attachment = m_context.attachments.at(attachmentIndex);

		if (auto pval = std::get_if<std::shared_ptr<GLRenderbuffer>>(&attachment); pval && *pval)
		{
			return **pval;
		}
	}

	return std::nullopt;
}

template<>
void OvRendering::HAL::GLFramebuffer::Resize(uint16_t p_width, uint16_t p_height, bool p_forceUpdate)
{
	OVASSERT(IsValid(), "Cannot resize an invalid framebuffer");

	if (p_forceUpdate || p_width != m_context.width || p_height != m_context.height)
	{
		m_context.width = p_width;
		m_context.height = p_height;

		for (auto& attachment : m_context.attachments)
		{
			if (const auto pval = std::get_if<std::shared_ptr<GLTexture>>(&attachment.second); pval && *pval)
			{
				(*pval)->Resize(m_context.width, m_context.height);
			}
			else if (const auto* pval = std::get_if<std::shared_ptr<GLRenderbuffer>>(&attachment.second); pval && *pval)
			{
				(*pval)->Resize(m_context.width, m_context.height);
			}
		}
	}
}

template<>
void OvRendering::HAL::GLFramebuffer::SetTargetDrawBuffer(std::optional<uint32_t> p_index)
{
	OVASSERT(IsValid(), "Invalid framebuffer");

	Bind();

	if (p_index.has_value())
	{
		glDrawBuffer(GL_COLOR_ATTACHMENT0 + p_index.value());
	}
	else
	{
		glDrawBuffer(GL_NONE);
	}

	Unbind();
}

template<>
void OvRendering::HAL::GLFramebuffer::SetTargetReadBuffer(std::optional<uint32_t> p_index)
{
	OVASSERT(IsValid(), "Invalid framebuffer");

	Bind();

	if (p_index.has_value())
	{
		glReadBuffer(GL_COLOR_ATTACHMENT0 + p_index.value());
	}
	else
	{
		glReadBuffer(GL_NONE);
	}

	Unbind();
}

template<>
uint32_t OvRendering::HAL::GLFramebuffer::GetID() const
{
	return m_context.id;
}

template<>
uint16_t OvRendering::HAL::GLFramebuffer::GetWidth() const
{
	OVASSERT(IsValid(), "Cannot get width of an invalid framebuffer");
	return m_context.width;
}

template<>
uint16_t OvRendering::HAL::GLFramebuffer::GetHeight() const
{
	OVASSERT(IsValid(), "Cannot get height of an invalid framebuffer");
	return m_context.height;
}

template<>
void OvRendering::HAL::GLFramebuffer::BlitToBackBuffer(uint16_t p_backBufferWidth, uint16_t p_backBufferHeight) const
{
	OVASSERT(IsValid(), "Cannot blit an invalid framebuffer");

	glBlitNamedFramebuffer(
		m_context.id, 0,
		0, 0, m_context.width, m_context.height,
		0, 0, p_backBufferWidth, p_backBufferHeight,
		GL_COLOR_BUFFER_BIT, GL_LINEAR
	);
}

template<>
void OvRendering::HAL::GLFramebuffer::ReadPixels(
	uint32_t p_x,
	uint32_t p_y,
	uint32_t p_width,
	uint32_t p_height,
	Settings::EPixelDataFormat p_format,
	Settings::EPixelDataType p_type,
	void* p_data) const
{
	OVASSERT(IsValid(), "Cannot read pixels from an invalid framebuffer");
	OVASSERT(p_width > 0 && p_height > 0, "Invalid read size");

	Bind();
	glReadPixels(
		p_x, p_y,
		p_width,
		p_height,
		EnumToValue<GLenum>(p_format),
		EnumToValue<GLenum>(p_type),
		p_data
	);
	Unbind();
}
