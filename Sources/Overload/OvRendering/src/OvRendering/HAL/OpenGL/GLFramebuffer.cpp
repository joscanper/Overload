/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvDebug/Assertion.h>
#include <OvRendering/HAL/OpenGL/GLFramebuffer.h>
#include <OvRendering/HAL/OpenGL/GLTextureHandle.h>

template<>
OvRendering::HAL::GLFramebuffer::TFramebuffer(uint16_t p_width, uint16_t p_height, bool p_depthOnly) :
	m_context {
		.width = p_width, 
		.height = p_height,
		.depthOnly = p_depthOnly
	}
{
	glGenFramebuffers(1, &m_context.bufferID);

	if (!m_context.depthOnly)
	{
		glGenRenderbuffers(1, &m_context.depthStencilBuffer);
	}

	// Setup texture
	m_context.renderTexture.Bind();

	Settings::TextureDesc renderTextureDesc{
		.width = m_context.width,
		.height = m_context.height,
		.firstFilter = Settings::ETextureFilteringMode::NEAREST,
		.secondFilter = Settings::ETextureFilteringMode::NEAREST,
		.horizontalWrapMode = Settings::ETextureWrapMode::CLAMP_TO_BORDER,
		.verticalWrapMode = Settings::ETextureWrapMode::CLAMP_TO_BORDER,
		.internalFormat = m_context.depthOnly ? Settings::EInternalFormat::DEPTH_COMPONENT : Settings::EInternalFormat::RGBA32F,
		.format = m_context.depthOnly ? Settings::EFormat::DEPTH_COMPONENT : Settings::EFormat::RGBA,
		.type = Settings::EPixelDataType::FLOAT
	};

	m_context.renderTexture.Upload(renderTextureDesc, nullptr);

	if (m_context.depthOnly)
	{
		float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	}

	m_context.renderTexture.Unbind();

	// Setup framebuffer
	Bind();

	if (m_context.depthOnly)
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_context.renderTexture.GetID(), 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
	}
	else
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_context.renderTexture.GetID(), 0);

		// Setup depth-stencil buffer
		// TODO: separated RenderBuffer into its own class
		glBindRenderbuffer(GL_RENDERBUFFER, m_context.depthStencilBuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_STENCIL, m_context.width, m_context.height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_context.depthStencilBuffer);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_context.depthStencilBuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	Unbind();
}

template<>
OvRendering::HAL::GLFramebuffer::~TFramebuffer()
{
	glDeleteFramebuffers(1, &m_context.bufferID);
	if (!m_context.depthOnly)
	{
		glDeleteRenderbuffers(1, &m_context.depthStencilBuffer);
	}
}

template<>
void OvRendering::HAL::GLFramebuffer::Bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_context.bufferID);
}

template<>
void OvRendering::HAL::GLFramebuffer::Unbind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

template<>
void OvRendering::HAL::GLFramebuffer::Resize(uint16_t p_width, uint16_t p_height, bool p_forceUpdate)
{
	if (p_forceUpdate || p_width != m_context.width || p_height != m_context.height)
	{
		m_context.width = p_width;
		m_context.height = p_height;

		auto desc = m_context.renderTexture.GetDesc();
		desc.width = m_context.width;
		desc.height = m_context.height;
		m_context.renderTexture.Bind();
		m_context.renderTexture.Upload(desc, nullptr);
		m_context.renderTexture.Unbind();

		if (!m_context.depthOnly)
		{
			// Resize depth-stencil buffer
			glBindRenderbuffer(GL_RENDERBUFFER, m_context.depthStencilBuffer);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_STENCIL, m_context.width, m_context.height);
			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}
	}
}

template<>
uint32_t OvRendering::HAL::GLFramebuffer::GetID() const
{
	return m_context.bufferID;
}

template<>
uint32_t OvRendering::HAL::GLFramebuffer::GetTextureID() const
{
	return m_context.renderTexture.GetID();
}

template<>
OvRendering::HAL::GLTextureHandle OvRendering::HAL::GLFramebuffer::GetTexture() const
{
	return HAL::GLTextureHandle{ m_context.renderTexture };
}

template<>
uint32_t OvRendering::HAL::GLFramebuffer::GetRenderBufferID() const
{
	return m_context.depthStencilBuffer;
}

template<>
uint16_t OvRendering::HAL::GLFramebuffer::GetWidth() const
{
	return m_context.width;
}

template<>
uint16_t OvRendering::HAL::GLFramebuffer::GetHeight() const
{
	return m_context.height;
}

template<>
void OvRendering::HAL::GLFramebuffer::GenerateMipMaps() const
{
	glBindTexture(GL_TEXTURE_2D, m_context.renderTexture.GetID());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

template<>
void OvRendering::HAL::GLFramebuffer::BlitToBackBuffer(uint16_t p_backBufferWidth, uint16_t p_backBufferHeight) const
{
	glBlitNamedFramebuffer(m_context.bufferID, 0,
		0, 0, m_context.width, m_context.height,
		0, 0, p_backBufferWidth, p_backBufferHeight,
		GL_COLOR_BUFFER_BIT, GL_LINEAR);
}
