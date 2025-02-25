/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TTexture.h>
#include <OvRendering/HAL/None/NoneTextureHandle.h>

namespace OvRendering::HAL
{
	struct NoneTextureContext {};
	using NoneTexture = TTexture<Settings::EGraphicsBackend::NONE, NoneTextureContext, NoneTextureHandleContext>;
}
