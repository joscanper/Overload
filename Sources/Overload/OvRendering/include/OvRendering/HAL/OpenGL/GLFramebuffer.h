/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TFramebuffer.h>
#include <OvRendering/HAL/OpenGL/GLTextureHandle.h>

namespace OvRendering::HAL
{
	struct GLFramebufferContext
	{
		uint16_t width = 0;
		uint16_t height = 0;
		bool depthOnly = false;
		uint32_t bufferID = 0;
		uint32_t depthStencilBuffer = 0;
		GLTexture renderTexture;
	};

	using GLFramebuffer = TFramebuffer<Settings::EGraphicsBackend::OPENGL, GLFramebufferContext, GLTextureHandleContext>;
}
