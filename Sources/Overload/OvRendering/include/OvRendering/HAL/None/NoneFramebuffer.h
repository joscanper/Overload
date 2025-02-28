/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TFramebuffer.h>
#include <OvRendering/HAL/None/NoneTexture.h>
#include <OvRendering/HAL/None/NoneRenderbuffer.h>

namespace OvRendering::HAL
{
	struct NoneFramebufferContext
	{
		uint16_t width = 0;
		uint16_t height = 0;
		bool depthOnly = false;
		bool allocated = false;
	};

	using NoneFramebuffer = TFramebuffer<Settings::EGraphicsBackend::NONE, NoneFramebufferContext, NoneTextureContext, NoneTextureHandleContext, NoneRenderbufferContext>;
}
