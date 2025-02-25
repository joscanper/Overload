/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TFramebuffer.h>
#include <OvRendering/HAL/None/NoneTextureHandle.h>

namespace OvRendering::HAL
{
	struct NoneFramebufferContext {};
	using NoneFramebuffer = TFramebuffer<Settings::EGraphicsBackend::NONE, NoneFramebufferContext, NoneTextureHandleContext>;
}
