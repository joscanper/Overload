/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/


#include <iostream>

#include <GL/glew.h>

#include <OvDebug/Assertion.h>
#include <OvRendering/HAL/OpenGL/GLFramebuffer.h>

template<>
OvRendering::HAL::GLFramebuffer::TFramebuffer(uint16_t p_width, uint16_t p_height, bool p_depthOnly) :
	m_context {
		.width = p_width, 
		.height = p_height,
		.depthOnly = p_depthOnly
	}
{
	// Generate OpenGL objects
	glGenFramebuffers(1, &m_context.bufferID);
	glGenTextures(1, &m_context.renderTexture);
	if (!m_context.depthOnly)
	{
		glGenRenderbuffers(1, &m_context.depthStencilBuffer);
	}

	// Setup texture
	glBindTexture(GL_TEXTURE_2D, m_context.renderTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	if (m_context.depthOnly)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_context.width, m_context.height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
		float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, m_context.width, m_context.height, 0, GL_RGBA, GL_FLOAT, nullptr);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);

	// Setup framebuffer
	Bind();
	if (m_context.depthOnly)
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_context.renderTexture, 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
	}
	else
	{
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_context.renderTexture, 0);

		// Setup depth-stencil buffer
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
	// Destroy OpenGL objects
	glDeleteFramebuffers(1, &m_context.bufferID);
	glDeleteTextures(1, &m_context.renderTexture);
	if (!m_context.depthOnly) {
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

		// Resize texture
		glBindTexture(GL_TEXTURE_2D, m_context.renderTexture);
		if (m_context.depthOnly) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_context.width, m_context.height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
		}
		else {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, m_context.width, m_context.height, 0, GL_RGBA, GL_FLOAT, nullptr);
		}
		glBindTexture(GL_TEXTURE_2D, 0);

		if (!m_context.depthOnly) {
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
	return m_context.renderTexture;
}

template<>
OvRendering::Resources::TextureHandle OvRendering::HAL::GLFramebuffer::GetTexture() const
{
	return Resources::TextureHandle(m_context.renderTexture);
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
	glBindTexture(GL_TEXTURE_2D, m_context.renderTexture);
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
