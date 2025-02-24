/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/HAL/Common/TTexture.h"

namespace OvRendering::HAL
{
	struct GLTextureContext {};
	using GLTexture = TTexture<Settings::EGraphicsBackend::OPENGL, GLTextureContext>;
}
