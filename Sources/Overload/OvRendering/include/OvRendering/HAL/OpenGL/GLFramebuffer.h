/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <unordered_map>

#include <OvRendering/HAL/Common/TFramebuffer.h>
#include <OvRendering/HAL/OpenGL/GLTexture.h>
#include <OvRendering/HAL/OpenGL/GLRenderbuffer.h>

namespace OvRendering::HAL
{
	template<Settings::EGraphicsBackend Backend, class GLTextureContext, class GLTextureHandleContext, class GLRenderbufferContext>
	struct TGLFramebufferContext
	{
		using Attachment = TFramebufferAttachment<Backend, GLTextureContext, GLTextureHandleContext, GLRenderbufferContext>;

		std::unordered_map<uint32_t, Attachment> attachments;
		uint16_t width = 0;
		uint16_t height = 0;
		bool depthOnly = false;
		uint32_t id = 0;
	};

	using GLFramebufferContext = TGLFramebufferContext<
		Settings::EGraphicsBackend::OPENGL,
		GLTextureContext,
		GLTextureHandleContext,
		GLRenderbufferContext
	>;

	using GLFramebuffer = TFramebuffer<
		Settings::EGraphicsBackend::OPENGL,
		GLFramebufferContext,
		GLTextureContext,
		GLTextureHandleContext,
		GLRenderbufferContext
	>;
}
