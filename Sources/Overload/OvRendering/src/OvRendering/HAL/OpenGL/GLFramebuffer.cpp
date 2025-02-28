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
	OVASSERT(IsValid(), "Cannot set an attachment on an invalid framebuffer");
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
	OVASSERT(IsValid(), "Cannot set an attachment on an invalid framebuffer");
	OVASSERT(p_toAttach != nullptr, "Cannot attach a null texture");

	const auto attachmentIndex = EnumToValue<GLenum>(p_attachment) + static_cast<GLenum>(p_index);
	Bind();
	glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentIndex, GL_TEXTURE_2D, p_toAttach->GetID(), 0);
	Unbind();
	m_context.attachments[attachmentIndex] = p_toAttach;
}

template<>
OvRendering::HAL::GLFramebuffer::TFramebuffer(uint16_t p_width, uint16_t p_height, bool p_depthOnly) :
	m_context {
		.width = p_width, 
		.height = p_height,
		.depthOnly = p_depthOnly
	}
{
	glGenFramebuffers(1, &m_context.id);

	m_context.width = std::max(static_cast<uint16_t>(1), m_context.width);
	m_context.height = std::max(static_cast<uint16_t>(1), m_context.height);

	std::shared_ptr<GLRenderbuffer> renderbuffer;
	std::shared_ptr<GLTexture> renderTexture = std::make_shared<GLTexture>();

	if (!m_context.depthOnly)
	{
		renderbuffer = std::make_shared<GLRenderbuffer>();
	}

	Settings::TextureDesc renderTextureDesc{
		.width = m_context.width,
		.height = m_context.height,
		.minFilter = Settings::ETextureFilteringMode::LINEAR,
		.magFilter = Settings::ETextureFilteringMode::LINEAR,
		.horizontalWrap = Settings::ETextureWrapMode::CLAMP_TO_BORDER,
		.verticalWrap = Settings::ETextureWrapMode::CLAMP_TO_BORDER,
		.internalFormat = m_context.depthOnly ? Settings::EInternalFormat::DEPTH_COMPONENT : Settings::EInternalFormat::RGBA32F,
		.useMipMaps = false,
		.mutableDesc = Settings::MutableTextureDesc{
			.format = m_context.depthOnly ? Settings::EFormat::DEPTH_COMPONENT : Settings::EFormat::RGBA,
			.type = Settings::EPixelDataType::FLOAT
		}
	};

	renderTexture->Allocate(renderTextureDesc);

	if (m_context.depthOnly)
	{
		float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		renderTexture->Bind();
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor); // TODO: Move that to GLTexture
		renderTexture->Unbind();
	}

	if (m_context.depthOnly)
	{
		Attach<GLTexture>(renderTexture, Settings::EFramebufferAttachment::DEPTH);
		Bind();
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
		Unbind();
	}
	else
	{
		Attach<GLTexture>(renderTexture, Settings::EFramebufferAttachment::COLOR);

		renderbuffer->Allocate(m_context.width, m_context.height, Settings::EInternalFormat::DEPTH_STENCIL);
		Attach<GLRenderbuffer>(renderbuffer, Settings::EFramebufferAttachment::DEPTH);
		Attach<GLRenderbuffer>(renderbuffer, Settings::EFramebufferAttachment::STENCIL);
	}

	Bind();
	GLenum fboStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (fboStatus != GL_FRAMEBUFFER_COMPLETE)
	{
		OVLOG_ERROR("Framebuffer not complete!");
	}

	Unbind();
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

template<>
bool OvRendering::HAL::GLFramebuffer::IsValid() const
{
	return true;
}

template<>
template<>
OvTools::Utils::OptRef<OvRendering::HAL::GLTexture> OvRendering::HAL::GLFramebuffer::GetAttachment(OvRendering::Settings::EFramebufferAttachment p_attachment, uint32_t p_index) const
{
	OVASSERT(IsValid(), "Cannot get an attachment from an invalid framebuffer");

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
	OVASSERT(IsValid(), "Cannot get an attachment from an invalid framebuffer");

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
